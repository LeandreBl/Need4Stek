/*
** main.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May  2 18:25:14 2017 Léandre Blanchard
** Last update Tue Jun  6 14:26:22 2017 Léandre Blanchard
*/

#include <X11/Xlib.h>

#include "n4s.h"

static int	usage(void)
{
  my_printf(USAGE1, BOLDGREEN, USAGE2, RESET);
  return (1);
}

static void	free_main(t_player *players,
			  t_window *window,
			  t_texture *textures,
			  void *brk_ptr)
{
  int		fd;

  if ((fd = open("score.dat", O_WRONLY | O_APPEND | O_CREAT, 0666)) == -1)
    return;
  if ((int)timer.time > 5)
    dprintf(fd, "<%s> %dmin:%dsec\n", players[0].info->name,
	    (int)timer.time / 60, (int)timer.time % 60);
  close(fd);
  free_players(players);
  free_textures(textures);
  free_window(window);
  my_printf("%d\n", (long)brk_ptr);
}

static void	fill_nickname(t_player *players, char **av)
{
  int		kart;

  kart = rand() % NB_KARTS;
  players[0].info->skin = kart;
  if (my_strcmp(av[1], "--server") == 0)
    {
      av[2][NAME_SIZE - 1] = 0;
      my_strcpy(players[0].info->name, av[2]);
    }
  else
    {
      av[3][NAME_SIZE - 1] = 0;
      my_strcpy(players[0].info->name, av[3]);
    }
}

static int	error_gest(int ac, char **av)
{
  srand(time(NULL));
  XInitThreads();
  signal(SIGINT, sigquit_handler);
  if (ac < 3)
    return (-1);
  if (my_strcmp(av[1], "--server") == 0)
    if (av[2] != NULL)
      return (0);
  if (my_strcmp(av[1], "--join") == 0)
    if (av[2] != NULL)
      if (av[3] != NULL)
	return (0);
  return (-1);
}

int		main(int ac, char **av)
{
  t_window	*window;
  t_texture	*textures;
  t_player	*players;
  void		*a;

  a = sbrk(0);
  if (error_gest(ac, av) != 0)
    return (usage());
  if ((window = init_window(720, 16.0 / 9.0, "Tek_Kart")) == NULL)
    return (-1);
  if ((textures = init_textures()) == NULL)
    return (-1);
  if ((players = init_players(MAX_PLAYERS)) == NULL)
    return (-1);
  if ((window->font = my_strdup("fonts/arial.ttf")) == NULL)
    return (-1);
  if ((window->musics = init_musics()) == NULL)
      return (-1);
  fill_nickname(players, av);
  if (my_strcmp(av[1], "--server") == 0)
    lobby(window, textures, players);
  if (my_strcmp(av[1], "--join") == 0 && av[2] != NULL)
    client(window, textures, players, sfIpAddress_fromString(av[2]));
  free_main(players, window, textures, a);
  return (0);
}
