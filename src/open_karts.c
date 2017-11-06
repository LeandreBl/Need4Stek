/*
** open_karts.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May 16 14:48:31 2017 Léandre Blanchard
** Last update Wed Nov  1 17:20:43 2017 Léandre Blanchard
*/

#include <dirent.h>
#include "n4s.h"

char		**recup_karts(const char *path)
{
  struct dirent **namelist;
  char		**tab;
  int           n;
  int		i;

  n = scandir(path, &namelist, NULL, alphasort);
  if (n < 0)
    {
      perror("scandir");
      return (NULL);
    }
  tab = NULL;
  i = 0;
  while (i != n)
    {
      tab = tab_append(tab, my_strdup(namelist[i]->d_name));
      free(namelist[i]);
      i++;
    }
  free(namelist);
  return (tab);
}

int			all_karts(t_sprite ***sprites)
{
  char                  *s;
  char			**name_list;
  sfVector2i		xy;

  xy.x = -1;
  mprintf(BOX_, BOLDWHITE, RESET);
  if ((name_list = recup_karts(KART_FOLDER)) == NULL)
    return (-1);
  xy.y = 0;
  while (name_list[++xy.x])
    {
      if (end_with(name_list[xy.x], ".png") == 0)
	{
	  if ((s = catalloc("%s%s", KART_FOLDER, name_list[xy.x])) == NULL)
	    return (-1);
	  mprintf(BOLDRED);
	  if ((fill_karts(sprites[xy.y++], s)) == -1)
	    return (-1);
	  mprintf(KART_FOUND, BOLDGREEN, BOLDCYAN, s, BOLDGREEN, RESET);
	  free(s);
	}
      free(name_list[xy.x]);
    }
  free(name_list);
  return (0);
}
