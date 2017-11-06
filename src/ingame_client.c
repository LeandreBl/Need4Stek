/*
** ingame_client.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May  5 11:57:20 2017 Léandre Blanchard
** Last update Tue Jun  6 14:29:14 2017 Léandre Blanchard
*/

#include "n4s.h"

int		wait_music(t_window *window)
{
  static int	a;

  if (a == 1)
    return (0);
  sfMusic_play(window->musics[2]);
  while (sfMusic_getStatus(window->musics[2]) == sfPlaying);
  init_time(&timer);
  a = 1;
  init_music_properly(window);
  return (0);
}

int		ingame_client(t_window *window, t_texture *textures,
			      t_player *players)
{
  float		speed;

  put_sprite(window, textures->sprites[6], ORIGIN);
  window_refresh(window);
  if ((textures->map = receive_map(players)) == NULL)
    return (-1);
  players[0].info->pos = player_start(textures->map);
  if (init_minimap(textures) == -1)
    return (-1);
  while (sfRenderWindow_isOpen(window->window)
	 && players[1].info->status != -2)
    {
      window_clear(window);
      close_win(window);
      speed = move_me(textures->map, &players[0]);
      display_background(window, textures, players[0].info->dir);
      walls(window, textures->map, textures, &players[0]);
      minimap(textures, players, textures->map);
      somedisplay(window, textures, players, speed);
      wait_music(window);
    }
  sfMusic_stop(window->musics[0]);
  free_tab(&textures->map);
  return (0);
}
