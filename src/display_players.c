/*
** display_players.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May  5 12:10:22 2017 Léandre Blanchard
** Last update Tue Jun  6 15:16:49 2017 Léandre Blanchard
*/

#include "n4s.h"

float		cube(float a)
{
  a = (float)a * (float)a;
  return (a);
}

float		distance(sfVector2f me, sfVector2f you)
{
  float		dist;

  dist = sqrt(cube(you.x - me.x) + cube(you.y - me.y));
  return (dist);
}

float		angle(sfVector2f me, sfVector2f you,
		      sfVector2f point, sfVector2f dir_dist)
{
  sfVector3f	dist;
  float		angle;
  float		test;

  dist.x = dir_dist.x;
  dist.y = distance(me, point);
  dist.z = distance(you, point);
  angle = acos((cube(dist.x) + cube(dist.y) - cube(dist.z)) /
	       (2 * dist.x * dist.y));
  if (angle < 0 || angle > 90)
    return (-1);
  dist.z = distance(you, XY(me.x + TESTX, me.y - TESTY));
  test = acos((cube(dist.x) + cube(dist.y) - cube(dist.z)) /
	      (2 * dist.x * dist.y));
  if (test > M_PI / 4)
    return (M_PI / 2);
  return (angle);
}

static void	add_to_screen(t_window *window, t_sprite *sprite,
			      t_trigo t, char *name)
{
  sfVector2f	real;
  float		size;

  size = 6 / (t.dist / 2);
  real.x = t.from;
  real.y = H_2 + H_2 / t.dist;
  put_sprite_resize(window, sprite, real, XY(size, size));
  put_word(name, real, window, sfBlack);
}

int		display_players(t_window *window,
				t_texture *textures, t_player *players)
{
  int		i;
  t_trigo	t;

  i = 1;
  while (i != MAX_PLAYERS)
    {
      if (players[i].info->status >= 0
	  && can_see(players[0].info->pos, players[i].info->pos,
		     textures->map))
	{
	  t.point = XY(players[0].info->pos.x + TRACEX,
		     players[0].info->pos.y - TRACEY);
	  t.dist = distance(players[0].info->pos, players[i].info->pos);
	  if ((t.ang = ANGL, t.point, XY(t.dist, PDIR))) == -1)
	    return (0);
	  t.from = PROJ * sin(t.ang) / sin(t.ang + M_PI / 2);
	  if (t.from > 640)
	    t.from = 640 + (t.from - 640) / 2.5;
	  if (t.from > 0)
	    add_to_screen(window, textures->karts[players[i].info->skin][5],
			  t, players[i].info->name);
	}
      i++;
    }
  return (0);
}
