/*
** load_sprites.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 21:07:41 2017 Léandre Blanchard
** Last update Fri Jun  2 12:40:38 2017 Léandre Blanchard
*/

#include "n4s.h"

static t_sprite		*load_one(const char *pathname, const char *name)
{
  t_sprite		*sprite;

  if ((sprite = create_sprite(pathname)) == NULL)
    return (NULL);
  my_printf(SPRITE_FOUND, BOLDGREEN, BOLDYELLOW, name,
	    BOLDGREEN, RESET);
  return (sprite);
}

int			all_sprites(t_sprite **sprites)
{
  int                   i;

  sprites[0] = load_one("sprites/lobby.png", "lobby");
  sprites[1] = load_one("sprites/button.png", "button");
  sprites[2] = load_one("sprites/button_pressed.png", "button_pressed");
  sprites[3] = load_one("sprites/clouds.png", "clouds");
  sprites[4] = load_one("sprites/road.png", "road");
  sprites[5] = load_one("sprites/speedometer.png", "speedometer");
  sprites[6] = load_one("sprites/loading.png", "loading logo");
  sprites[7] = NULL;
  i = 0;
  while (i != NB_SPRITES)
    if (sprites[i++] == NULL)
      return (-1);
  my_printf(BOX_, BOLDWHITE, RESET);
  return (0);
}
