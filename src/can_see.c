/*
** can_see.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Jun  1 17:07:39 2017 Léandre Blanchard
** Last update Tue Jun  6 15:11:27 2017 Léandre Blanchard
*/

#include <stdio.h>
#include "n4s.h"

static void	swaper(sfVector2f *from, sfVector2f *to)
{
  sfVector2f	swp;

  if (from->x > to->x)
    {
      swp = *from;
      *from = *to;
      *to = swp;
    }

}

int	can_see(sfVector2f from, sfVector2f to, char **map)
{
  float	a;
  float	x;
  float	b;
  float	y;

  swaper(&from, &to);
  a = (to.y - from.y) / (to.x - from.x);
  b = from.y - (a * from.x);
  x = from.x;
  return (1);
  while (x < to.x)
    {
      y = a * x + b;
      if (x >= 0 && x < my_tablen(map) &&
	  y >= 0 && y < my_strlen(map[(int)x]))
	if (map[(int)x][(int)y] != '0')
	  return (0);
      x += 2;
    }
  return (1);
}
