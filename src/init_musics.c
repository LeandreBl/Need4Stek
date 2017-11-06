/*
** init_musics.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May  5 11:12:17 2017 Léandre Blanchard
** Last update Wed Nov  1 17:19:32 2017 Léandre Blanchard
*/

#include "n4s.h"

int             init_minimap(t_texture *textures)
{
  int           width;
  int           height;
  char		**map;

  map = textures->map;
  width = max_len(map) + 1;
  height = tablen(map) + 1;
  if ((textures->smap = malloc(sizeof(t_sprite))) == NULL)
    return (-1);
  if ((textures->pmap = malloc(sizeof(sfUint8) * width * height * 4)) == NULL)
    return (-1);
  textures->smap->texture = sfTexture_create(width, height);
  textures->smap->sprite = sfSprite_create();
  return (0);
}

static sfMusic	*load_one(const char *pathname, const char *name)
{
  sfMusic	*music;

  if ((music = sfMusic_createFromFile(pathname)) == NULL)
    return (NULL);
  mprintf(MUSIC_FOUND, BOLDBLUE, BOLDWHITE, name, BOLDBLUE, RESET);
  return (music);
}

static int	init_all_musics(sfMusic **musics)
{
  int		i;

  musics[0] = load_one("musics/mario_kart.wav", "default_sound");
  musics[1] = load_one("musics/forward.wav", "default_motor");
  musics[2] = load_one("musics/countdown.wav", "start sound");
  musics[3] = load_one("musics/skid.ogg", "skid sound");
  musics[NB_SOUNDS] = NULL;
  i = 0;
  while (musics[i] != NULL)
    i++;
  if (i != NB_SOUNDS)
    return (-1);
  return (0);
}

sfMusic		**init_musics(void)
{
  sfMusic	**musics;

  if ((musics = malloc(sizeof(sfMusic *) * (NB_SOUNDS + 1))) == NULL)
    return (NULL);
  if (init_all_musics(musics) == -1)
    return (NULL);
  return (musics);
}
