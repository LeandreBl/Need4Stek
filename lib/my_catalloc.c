/*
** my_catalloc.c for my_catalloc in /home/leandre/System_unix/PSU_2016_minishell2
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Apr  3 19:27:11 2017 Léandre Blanchard
** Last update Thu Jun  1 14:37:54 2017 Léandre Blanchard
*/

#include "my.h"

char		*my_catalloc(const char *s,
			     const char *s_2, const char *s_3)
{
  char		*out;
  int		len;

  len = my_strlen(s) + my_strlen(s_2) + my_strlen(s_3);
  if (s == NULL)
    return (NULL);
  if ((out = my_calloc(len + 1)) == NULL)
    return (NULL);
  my_strcat(out, s);
  my_strcat(out, s_2);
  my_strcat(out, s_3);
  return (out);
}
