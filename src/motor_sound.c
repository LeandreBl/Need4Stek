/*
** motor_sound.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May  5 17:10:35 2017 Léandre Blanchard
** Last update Sun May  7 00:02:41 2017 Léandre Blanchard
*/

#include "n4s.h"

void			vary_motor(sfMusic *motor, float speed)
{
  if (speed < 0.5)
    sfMusic_setVolume(motor, 0);
  else
    sfMusic_setVolume(motor, 70);
  if (sfMusic_getStatus(motor) == sfStopped)
    sfMusic_play(motor);
  sfMusic_setPitch(motor, speed * 0.8 / MAX_SPEED);
}
