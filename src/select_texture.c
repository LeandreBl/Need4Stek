/*
** select_texture.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 21:10:06 2017 Léandre Blanchard
** Last update Thu May  4 21:13:14 2017 Léandre Blanchard
*/

#include "n4s.h"

int			change(sfVector2f ray, sfVector2f prev,
			       int *change, float *dist)
{
  if ((int)ray.x != (int)prev.x || (int)ray.y != (int)prev.y)
    {
      if ((int)ray.y != (int)prev.y)
	(*change = 1);
      else
	(*change = 0);
    }
  if (*change == 1)
    *dist = TEXTURE_SIZE * fmodf(ray.x, 1);
  else
    *dist = TEXTURE_SIZE * fmodf(ray.y, 1);
  return (0);
}

int			select_texture(char c)
{
  if (c == '<' || c == 'v')
    return (2);
  if (c == '>' || c == 'A')
    return (1);
  return (0);
}

void                    special_clear(t_window *window)
{
  int                   i;

  i = 0;
  while (i < 4 * window->width * window->height)
    window->pixels[i++] = 0;
}
