/*
** bg_video.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Jun  1 14:31:57 2017 Léandre Blanchard
** Last update Mon Jun  5 17:03:31 2017 Léandre Blanchard
*/

#include "n4s.h"

void			bg_video(t_window *window, t_sprite **video)
{
  static float		a;

  put_sprite(window, video[(int)a], ORIGIN);
  a += 0.015;
  if (video[(int)a] == NULL)
    a = 0;
}

static int		add_one(int j, t_sprite **video,
				const char *name, const char *pathname)
{
  char			*s;

  if ((s = my_catalloc(pathname, "/", name)) == NULL)
    return (-1);
  if ((video[j] = create_sprite(s)) == NULL)
    return (-1);
  free(s);
  return (0);
}

t_sprite		**create_videomode(const char *pathname)
{
  char			**names;
  t_sprite		**video;
  int			i;
  int			j;

  i = 0;
  j = 0;
  if ((names = recup_karts(pathname)) == NULL)
    return (NULL);
  if ((video = create_sprites(my_tablen(names) - 2)) == NULL)
    return (NULL);
  while (names[i] != NULL)
    {
      if (end_with(names[i], ".png") == 0)
	if ((add_one(j++, video, names[i], pathname)) == -1)
	  return (NULL);
      i++;
    }
  free_tab(names);
  return (video);
}
