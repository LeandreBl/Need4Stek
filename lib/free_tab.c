/*
** free_tab.c for free_tab in /home/leandre/libmy/
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Feb 28 14:14:05 2017 Léandre Blanchard
** Last update Sun May 28 17:54:23 2017 Léandre Blanchard
*/

#include "my.h"

void	        free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	my_free(tab[i++]);
      my_free(tab);
      tab = NULL;
    }
}
