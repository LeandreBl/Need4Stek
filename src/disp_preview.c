/*
** disp_preview.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon May 29 12:39:10 2017 Léandre Blanchard
** Last update Fri Jun  9 08:36:04 2017 Léandre Blanchard
*/

#include "n4s.h"

int			reload(char **map_name, int i, t_preview *prev)
{
  int			j;

  j = 0;
  free_tab(prev->current);
  my_free(prev->pixels);
  my_free(prev->name);
  free_sprite(prev->preview);
  if ((prev->current = load_file(map_name[i])) == NULL)
    return (-1);
  while (prev->current[j] != NULL)
    my_revstr(prev->current[j++]);
  init_preview(prev);
  preview(prev);
  if ((prev->name = my_strdup(map_name[i])) == NULL)
    return (-1);
  shift_left(prev->name, my_strlen(MAP_FOLDER));
  return (0);
}

int			swap_map(char **map_name, t_preview *prev, int *from)
{
  static int		i;

  if (key_released(sfKeyRight))
    {
      i = (i + 1) % (my_tablen(map_name));
      if (reload(map_name, i, prev) == -1)
	return (-1);
      *from = 1;
      return (1);
    }
  else if (key_released(sfKeyLeft))
    {
      i = (i == 0) ? (my_tablen(map_name) - 1) : (i - 1);
      *from = 0;
      reload(map_name, i, prev);
      return (1);
    }
  return (0);
}

static void		slide_in(t_window *window, t_sprite *sprite,
				 sfVector2i size, int from)
{
  sfVector2f		pos;
  float			speed;

  pos.y = H_2 - size.y;
  if (from == 0)
    pos.x = -size.x * 2;
  else
    pos.x = W_;
  speed = 10;
  while (sfRenderWindow_isOpen(window->window))
    {
      window_clear(window);
      put_png(window, ORIGIN, "sprites/loading.png");
      close_win(window);
      put_sprite_resize(window, sprite, pos, XY(10, 10));
      pos.x += (from == 1) ? (-speed) : speed;
      speed -= 0.04;
      window_refresh(window);
      if (from == 1 && pos.x <= W_2 - size.x)
	break;
      else if (from == 0 && pos.x >= W_2 - size.x)
	break;
    }
}

int			display_preview(t_window *window,
				char **map_name,
				t_preview *prev)
{
  sfVector2i		size;
  t_sprite		**video;
  int			status;
  int			from;

  if ((video = create_videomode("video")) == NULL)
    return (-1);
  while (sfRenderWindow_isOpen(window->window) && !KP(sfKeyReturn))
    {
      window_clear(window);
      close_win(window);
      size = XYI(max_len(prev->current) * 5, my_tablen(prev->current) * 5);
      bg_video(window, video);
      put_word(prev->name, XY(W_2 - my_strlen(prev->name) * 7, 50),
	       window, sfBlack);
      put_sprite_resize(window, prev->preview, XY(W_2 - size.x,
						 H_2 - size.y), XY(10, 10));
      if ((status = swap_map(map_name, prev, &from)) == -1)
	return (-1);
      size = XYI(max_len(prev->current) * 5, my_tablen(prev->current) * 5);
      (status == 1) ? slide_in(window, prev->preview, size, from) : 0;
      window_refresh(window);
    }
  free_sprites(video);
  return (0);
}

int			preview(t_preview *prev)
{
  int			i;
  int			j;
  t_minimap		info;

  i = 0;
  while (i != my_tablen(prev->current))
    {
      j = 0;
      while (j != my_strlen(prev->current[i]))
	{
	  info.width = my_strlen(prev->current[i]);
	  info.height = my_tablen(prev->current);
	  info.color = select_color(prev->current, i, j);
	  put_mini_pixel(prev->pixels, info.width - j, i, info);
	  j++;
	}
      i++;
    }
  sfTexture_updateFromPixels(prev->preview->texture,
			     prev->pixels, my_strlen(prev->current[0]),
			     my_tablen(prev->current), 0, 0);
  sfSprite_setTexture(prev->preview->sprite, prev->preview->texture, sfTrue);
  return (0);
}
