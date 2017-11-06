/*
** raycat.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 12:45:48 2017 Léandre Blanchard
** Last update Tue May 30 19:36:25 2017 Léandre Blanchard
*/

#include "n4s.h"

static sfVector2f	move_forward(sfVector2f pos, float direction,
				     float distance)
{
  direction = direction * M_PI / 180;
  pos.x = pos.x + distance * cos(direction);
  pos.y = pos.y - distance * sin(direction);
  return (pos);
}

t_cast			raycast(sfVector2f pos, float direction, char **map)
{
  sfVector2f		ray;
  t_cast		dist;
  sfVector2f		prev;
  float			size;
  sfVector2i		mapsize;

  size = DIST_;
  ray.x = pos.x;
  ray.y = pos.y;
  prev = ray;
  mapsize = XYI(my_strlen(map[0]), tablen(map));
  while (map[(int)ray.y][(int)ray.x] == '0'
	 && ray.y < mapsize.y && ray.x < mapsize.x)
    {
      prev = ray;
      ray = move_forward(ray, direction, size);
      dist.texture = select_texture(map[(int)ray.y][(int)ray.x]);
      dist.dist = sqrt(((pos.x - ray.x) * (pos.x - ray.x))
		       + ((pos.y - ray.y) * (pos.y - ray.y)));
      if (dist.dist > 20)
	size = 0.05;
    }
  change(ray, prev, &dist.change, &dist.x);
  return (dist);
}

void			draw_column(t_window *window, sfVector2f from,
				    t_cast dist, t_texture *textures)
{
  int			y;
  sfImage		**images;
  sfColor		color;
  int			i;

  images = textures->images;
  i = 0;
  y = from.y;
  while (y < from.y + dist.wall_h - 1 && y < H_ - 1)
    {
      color = sfImage_getPixel(images[dist.texture],
	 (int)dist.x % (TEXTURE_SIZE - 2), (float)TEXTURE_SIZE / dist.wall_h * i);
      if (dist.change == 0)
	color = sfColor_fromRGB(color.r / 2, color.g / 2, color.b / 2);
      my_put_pixel(window, from.x, y, color);
      y++;
      i++;
    }
}

void			walls(t_window *window, char **map,
			      t_texture *textures, t_player *player)
{
  int			x;
  t_cast		dist;
  float			angle;

  angle = FOV / (-2);
  dist.dist = 0;
  x = 0;
  special_clear(window);
  while (x < window->width)
    {
      dist = raycast(player->info->pos, player->info->dir + angle, map);
      dist.dist *= cos((float)M_PI / (float)200 * angle);
      if (dist.dist < 0.05)
	dist.dist = 0.05;
      dist.wall_h = PROJ / dist.dist / 2;
      draw_column(window, XY(x, H_2 - dist.wall_h / 2), dist, textures);
      angle += (float)FOV / (float)W_;
      x++;
    }
}
