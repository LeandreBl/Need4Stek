/*
** free.c for h4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May  2 19:00:59 2017 Léandre Blanchard
** Last update Tue May 30 19:44:58 2017 Léandre Blanchard
*/

#include "n4s.h"

void		free_images(sfImage **images)
{
  int		i;

  i = 0;
  if (images != NULL)
    {
      while (images[i] != NULL)
	{
	  sfImage_destroy(images[i]);
	  i++;
	}
      my_free(images);
    }
}

void		free_all_sprites(t_sprite ***sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      while (sprites[i] != NULL)
	free_sprites_only(sprites[i++]);
      my_free(sprites);
    }
}

void		free_sprite_spec(t_sprite **sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      while (sprites[i] != NULL)
	{
	  sfSprite_destroy(sprites[i]->sprite);
	  i++;
	}
      sfTexture_destroy(sprites[0]->texture);
      my_free(sprites);
    }
}

void		free_textures(t_texture *textures)
{
  if (textures != NULL)
    {
      free_images(textures->images);
      free_all_sprites(textures->karts);
      free_sprite_spec(textures->lakitu);
      free_sprites(textures->sprites);
      my_free(textures);
    }
}

void		free_players(t_player *players)
{
  int		i;

  if (players != NULL)
    {
      i = 0;
      while (i != MAX_PLAYERS)
	{
	  my_free(players[i].info);
	  sfTcpSocket_destroy(players[i].socket);
	  i++;
	}
      my_free(players);
    }
}
