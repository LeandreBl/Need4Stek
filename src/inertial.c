/*
** inertial.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May  5 11:35:41 2017 Léandre Blanchard
** Last update Sat May  6 01:16:35 2017 Léandre Blanchard
*/

#include "n4s.h"

static void	inertial_acceleration(float *speed)
{
  if (*speed == 0)
    *speed = 0.15;
  if (*speed < MAX_SPEED && *speed > 0)
    {
      if (!KP(sfKeyLeft) && !KP(sfKeyRight)
	  && !KP(sfKeyQ) && !KP(sfKeyD))
	*speed *= ACCELERATION;
      else
	*speed *= ROLL_ACCELERATION;
    }
}

void		inertial(float *speed)
{
  if (KP(sfKeyUp) || KP(sfKeyZ))
    inertial_acceleration(speed);
  else if (KP(sfKeyDown) || KP(sfKeyS))
    {
      if (*speed >= 0)
	*speed -= 2;
      if (*speed <= 0 && *speed > -5)
	*speed -= 1 + (*speed * ACCELERATION);
    }
  else
    {
      if (*speed > 0)
	*speed /= 1.05;
      if (*speed < 0.05)
	*speed = 0;
    }
  if (*speed < -1)
    *speed = -1;
}
