/*
** minimap.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May  5 16:59:51 2017 Léandre Blanchard
** Last update Fri Jun  2 13:45:52 2017 Léandre Blanchard
*/

#include "n4s.h"

int		put_mini_pixel(sfUint8 *pixels, int x, int y, t_minimap info)
{
  x--;
  if (x < 0 || y < 0)
    return (-1);
  if (x > info.width || y > info.height)
    return (-1);
  pixels[(info.width * y + x) * 4 + 0] = info.color.r;
  pixels[(info.width * y + x) * 4 + 1] = info.color.g;
  pixels[(info.width * y + x) * 4 + 2] = info.color.b;
  pixels[(info.width * y + x) * 4 + 3] = info.color.a;
  return (0);
}

static sfColor	get_kart_color(int skin)
{
  if (skin == 0)
    return (sfColor_fromRGBA(255, 255, 0, 200));
  else if (skin == 1)
    return (sfColor_fromRGBA(51, 255, 51, 127));
  else if (skin == 2)
    return (sfColor_fromRGBA(255, 0, 0, 127));
  else if (skin == 3)
    return (sfColor_fromRGBA(255, 153, 51, 127));
  else if (skin == 4)
    return (sfColor_fromRGBA(0, 153, 153, 127));
  else if (skin == 5)
    return (sfColor_fromRGBA(51, 204, 51, 127));
  return (sfBlack);
}

static int	put_players_kart(t_player *players,
				 t_texture *textures, char **map)
{
  int		i;
  sfVector2i	pos;
  t_minimap	info;

  i = 0;
  while (i != MAX_PLAYERS)
    {
      pos = XYI((int)players[i].info->pos.x, (int)players[i].info->pos.y);
      info.width = my_strlen(map[pos.y]);
      info.height = tablen(map);
      info.color = get_kart_color(players[i].info->skin);
      if (players[i].info->skin >= 0)
	put_mini_pixel(textures->pmap, info.width - pos.x, pos.y, info);
      i++;
    }
  return (0);
}

sfColor		select_color(char **map, int i, int j)
{
  if (map[i][j] == '2')
    return (sfColor_fromRGBA(204, 102, 0, 127));
  else if (map[i][j] == '0')
    return (sfColor_fromRGBA(255, 255, 255, 127));
  else if (map[i][j] == 'A' || map[i][j] == 'v' ||
	   map[i][j] == '<' || map[i][j] == '>')
    return (sfColor_fromRGBA(0, 0, 200, 127));
  return (sfColor_fromRGBA(200, 0, 0, 127));
}

int		minimap(t_texture *textures,
			t_player *players, char **map)
{
  int		i;
  int		j;
  t_minimap	info;

  i = 0;
  while (i != tablen(map))
    {
      j = 0;
      while (j != my_strlen(map[i]))
	{
	  info.width = my_strlen(map[i]);
	  info.height = tablen(map);
	  info.color = select_color(map, i, j);
	  put_mini_pixel(textures->pmap, info.width - j, i, info);
	  j++;
	}
      i++;
    }
  put_players_kart(players, textures, map);
  sfTexture_updateFromPixels(textures->smap->texture,
			     textures->pmap, my_strlen(map[0]), tablen(map), 0, 0);
  sfSprite_setTexture(textures->smap->sprite, textures->smap->texture, sfTrue);
  return (0);
}
