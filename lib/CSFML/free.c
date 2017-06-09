/*
** free.c for my_csfml in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 14:48:58 2017 Léandre Blanchard
** Last update Sun May 28 17:56:55 2017 Léandre Blanchard
*/

#include "csfml.h"
#include "my.h"

void		free_sprites_only(t_sprite **sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      sfTexture_destroy(sprites[0]->texture);
      while (sprites[i] != NULL)
	{
	  if (sprites[i]->sprite != NULL)
	    sfSprite_destroy(sprites[i]->sprite);
	  my_free(sprites[i++]);
	}
      my_free(sprites);
    }
}

void		free_sprites(t_sprite **sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      while (sprites[i] != NULL)
	{
	  free_sprite(sprites[i]);
	  i++;
	}
      my_free(sprites);
    }
}

void		free_musics(sfMusic **musics)
{
  int		i;

  i = 0;
  if (musics != NULL)
    {
      while (musics[i] != NULL)
	{
	  sfMusic_destroy(musics[i]);
	  i++;
	}
      my_free(musics);
    }
}

void            free_sprite(t_sprite *sprite)
{
  if (sprite != NULL)
    {
      if (sprite->sprite != NULL)
	sfSprite_destroy(sprite->sprite);
      if (sprite->texture != NULL)
	sfTexture_destroy(sprite->texture);
      my_free(sprite);
    }
}

void            free_window(t_window *window)
{
  if (window != NULL)
    {
      if (window->window != NULL)
	sfRenderWindow_destroy(window->window);
      if (window->pixels != NULL)
	my_free(window->pixels);
      if (window->font != NULL)
	my_free(window->font);
      free_musics(window->musics);
      if (window->texture != NULL)
	sfTexture_destroy(window->texture);
      if (window->sprite != NULL)
	sfSprite_destroy(window->sprite);
      my_free(window);
    }
}
