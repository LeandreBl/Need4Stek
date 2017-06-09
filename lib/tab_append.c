/*
** tab_append.c for tab_append in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun May 14 20:03:11 2017 Léandre Blanchard
** Last update Thu May 25 19:21:50 2017 Léandre Blanchard
*/

#include "my.h"

char		**tab_append(char **tab, char *add)
{
  char		**new;
  int		i;
  int		ret;

  i = 0;
  ret = 0;
  if ((new = malloc(sizeof(char *) * (my_tablen(tab) + 2))) == NULL)
    return (NULL);
  while (tab != NULL && tab[i] != NULL)
    new[i] = tab[i++];
  new[i] = add;
  new[i + 1] = NULL;
  if (tab != NULL)
    my_free(tab);
  return (new);
}
