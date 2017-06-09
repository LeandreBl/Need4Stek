/*
** select_map.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon May 29 12:36:14 2017 Léandre Blanchard
** Last update Fri Jun  9 08:36:38 2017 Léandre Blanchard
*/

#include "n4s.h"

int                     init_preview(t_preview *prev)
{
  int                   width;
  int                   height;

  width = max_len(prev->current) + 1;
  height = my_tablen(prev->current) + 1;
  if ((prev->preview = malloc(sizeof(t_sprite))) == NULL)
    return (-1);
  if ((prev->pixels = pixels_buffer(width, height)) == NULL)
    return (-1);
  prev->preview->texture = sfTexture_create(width, height);
  prev->preview->sprite = sfSprite_create();
  return (0);
}

static char		**maps_name(void)
{
  struct dirent		*folder;
  DIR			*dir;
  char			**tab;
  char			*s;

  tab = NULL;
  if ((dir = opendir(MAP_FOLDER)) == NULL)
    return (NULL);
  while ((folder = readdir(dir)) != NULL)
    if (end_with(folder->d_name, ".n4s") == 0)
      {
	if ((s = my_catalloc(MAP_FOLDER, folder->d_name, NULL)) == NULL)
	  return (NULL);
	tab = tab_append(tab, s);
      }
  closedir(dir);
  return (tab);
}

static void		all_null(t_preview *prev)
{
  prev->name = NULL;
  prev->current = NULL;
  prev->preview = NULL;
  prev->pixels = NULL;
}

char			**select_map(t_window *window, sfMusic *music)
{
  char			**map_name;
  t_preview		prev;

  if ((map_name = maps_name()) == NULL)
    return (NULL);
  all_null(&prev);
  reload(map_name, 0, &prev);
  preview(&prev);
  if (display_preview(window, map_name, &prev) == -1)
    return (NULL);
  sfMusic_destroy(music);
  free_tab(map_name);
  free_sprite(prev.preview);
  my_free(prev.pixels);
  map_name = prev.current;
  return (map_name);
}
