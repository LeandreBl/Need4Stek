/*
** my_str_to_wordtab.c for str_wordtab in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr 26 19:18:18 2017 Léandre Blanchard
** Last update Thu May  4 19:57:17 2017 Léandre Blanchard
*/

#include "my.h"

typedef struct  s_tab
{
  char          **array;
  int           nb;
  int           i;
  int           y;
  int           k;
}               t_tab;

static int      count_words(const char *str, int separator)
{
  int           i;
  int           nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      while (str[i] && str[i] != separator)
	i++;
      nb++;
      while (str[i] && str[i] == separator)
	i++;
    }
  nb++;
  return (nb);
}

char		**my_str_to_wordtab(const char *str, int s)
{
  t_tab		tab;

  tab.i = 0;
  tab.y = 0;
  tab.k = 0;
  if ((tab.array = malloc(sizeof(*tab.array) * count_words(str, s))) == NULL)
    return (NULL);
  tab.nb = 0;
  while (str[tab.i])
    {
      tab.nb = tab.i;
      while (str[tab.nb] && str[tab.nb] != s && str[tab.nb])
	tab.nb++;
      if ((tab.array[tab.k] = malloc(sizeof(tab.array) * tab.nb)) == NULL)
	return (NULL);
      tab.nb = 0;
      tab.y = 0;
      while (str[tab.i] && str[tab.i] != s)
	tab.array[tab.k][tab.y++] = str[tab.i++];
      tab.array[tab.k++][tab.y] = '\0';
      while (str[tab.i] && str[tab.i] == s)
	tab.i++;
    }
  tab.array[tab.k] = NULL;
  return (tab.array);
}
