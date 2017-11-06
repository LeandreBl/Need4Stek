/*
** accelerator.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Jun 16 07:35:40 2017 Léandre Blanchard
** Last update Fri Jun 16 07:57:15 2017 Léandre Blanchard
*/

#include "n4s.h"

int		accelerator(t_window *window, float speed)
{
  float		angle;
  sfVector2f	rotor;
  sfVector2f	new;

  rotor = xy_vectorf(1219, 676);
  angle = 20 + 70 * speed;
  new.x = rotor.x - PROJX(80);
  new.y = rotor.y - PROJY(80);
  my_draw_line(window, rotor, new, sfWhite);
  return (0);
}
