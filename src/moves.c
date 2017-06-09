/*
** moves.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 13:24:36 2017 Léandre Blanchard
** Last update Sat May  6 00:09:21 2017 Léandre Blanchard
*/

#include "n4s.h"

float			move_me(char **map, t_player *player)
{
  static float		speed;
  static sfVector2f	security;
  int			reverse;

  reverse = 1;
  inertial(&speed);
  if (speed < 0)
    reverse = -1;
  if (speed != 0)
    {
      if (KP(sfKeyLeft) || KP(sfKeyQ))
	player->info->dir -= ((ROLL) * reverse);
      if (KP(sfKeyRight) || KP(sfKeyD))
	player->info->dir += ((ROLL) * reverse);
    }
  if (mv_up(player->info, map, speed) == -1)
    speed = 0;
  if (map[(int)player->info->pos.y][(int)player->info->pos.x] == '0')
    security = player->info->pos;
  if (map[(int)player->info->pos.y][(int)player->info->pos.x] != '0')
    player->info->pos = security;
  return (speed);
}

static void		new_pos(t_info *info, float speed)
{
  if (speed > 0)
    {
      info->pos.x += WALLX;
      info->pos.y -= WALLY;
    }
  if (speed < 0)
    {
      speed *= -1;
      info->pos.x -= MOVEX;
      info->pos.y += MOVEY;
    }
}

static void		real_pos(sfVector2f prev, t_info *info, float speed)
{
  info->pos.x = prev.x + MOVEX;
  info->pos.y = prev.y - MOVEY;
  if (info->dir < 0)
    info->dir = 360;
  if (info->dir > 360)
    info->dir = 0;
}

int			mv_up(t_info *info, char **map, float speed)
{
  sfVector2f		prev;

  prev = info->pos;
  new_pos(info, speed);
  if (map[(int)info->pos.y][(int)info->pos.x] != '0')
    {
      if (map[(int)info->pos.y][(int)prev.x] == '0')
	{
	  info->pos = prev;
	  return (-1);
	}
      if (map[(int)prev.y][(int)info->pos.x] == '0')
	{
	  info->pos = prev;
	  return (-1);
	}
      info->pos = prev;
      return (-1);
    }
  if (speed > 0)
    real_pos(prev, info, speed);
  return (0);
}
