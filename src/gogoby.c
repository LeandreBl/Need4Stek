/*
** gogoby.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 15:53:07 2017 Léandre Blanchard
** Last update Wed Nov  1 17:23:35 2017 Léandre Blanchard
*/

#include "n4s.h"

t_sprite		**lakitu(void)
{
  sfTexture             *texture;
  t_sprite		**sprites;
  int                   x;

  x = 0;
  if ((sprites = create_sprites(8)) == NULL)
    return (NULL);
  if ((texture = sfTexture_createFromFile("sprites/gobgoby.png",
					  NULL)) == NULL)
    return (NULL);
  while (sprites[x] != NULL)
    {
      sprites[x]->texture = texture;
      sprites[x]->sprite = sfSprite_create();
      sfSprite_setTexture(sprites[x]->sprite, texture, sfTrue);
      sfSprite_setTextureRect(sprites[x]->sprite,
			      (sfIntRect){x * 156, 0, 156, 211});
      x++;
    }
  mprintf(SPRITE_FOUND, BOLDBLUE, BOLDYELLOW, "gogoby.png MDR",
	    BOLDBLUE, RESET);
  return (sprites);
}
