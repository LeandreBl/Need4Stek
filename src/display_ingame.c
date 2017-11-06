/*
** display_ingame.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 21:13:50 2017 Léandre Blanchard
** Last update Fri Jun 16 07:55:54 2017 Léandre Blanchard
*/

#include "n4s.h"

sfVector2f		player_start(char **map)
{
  int                   i;
  int                   j;

  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != 0)
	{
	  if (map[i][j] == 'P')
	    {
	      map[i][j] = '0';
	      return (XY(j, i));
	    }
	  j++;
	}
      i++;
    }
  return (START);
}

static void		right_left(float *a, t_window *window, float speed)
{
  if (KP(sfKeyLeft) || KP(sfKeyQ))
    {
      if (*a > 5)
	*a = 5;
      if (*a > 1)
	*a -= 0.7;
    }
  else if (KP(sfKeyRight) || KP(sfKeyD))
    {
      if (*a < 5)
	*a = 5;
      if (*a <= 9)
	*a += 0.7;
    }
  else
    {
      if (*a > 5)
	*a -= 0.7;
      if (*a < 5)
	*a += 0.7;
    }
  if (*a >= 1 && *a < 9)
    sfMusic_setVolume(window->musics[3], 0);
  else
    sfMusic_setVolume(window->musics[3], 50 / (MAX_SPEED / speed));
}

void			display_me(t_window *window, t_texture *textures,
			   t_player *players, float speed)
{
  static float		a = 5;
  int			perc;

  right_left(&a, window, speed);
  if (speed == 0)
    a = 5;
  put_sprite_resize(window, textures->karts[players[0].info->skin][(int)a],
		    XY(W_2 - 90, H_ - 212), XY(6, 6));
  put_sprite(window, SPRITE(SPEEDOMETER), XY(W_ - 120, H_ - 102));
  if ((perc = (int)((float)100 / ((float)MAX_SPEED / speed))) > 100)
    perc = 100;
  put_number(perc, XY(W_ - 90, H_ - 70), window, sfWhite);
  put_word("%", XY(W_ - 50, H_ - 70), window, sfWhite);
}

void			display_background(t_window *window,
					   t_texture *textures, float dir)
{
  int			b;

  b = (int)dir * 15 % W_;
  put_sprite(window, SPRITE(ROAD), XY(0, H_2));
  put_sprite(window, SPRITE(CLOUDS), XY(-b, 0));
  put_sprite(window, SPRITE(CLOUDS), XY(W_ - b, 0));
  update_time(&timer);
}
