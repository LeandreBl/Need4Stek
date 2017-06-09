/*
** my_strcpy.c for my_strcpy in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 19:58:41 2016 Leandre Blanchard
** Last update Wed May  3 14:19:17 2017 Léandre Blanchard
*/

#include <stdlib.h>

int	my_strcpy(char *dest, const char *src)
{
  int	i;

  if (dest == NULL || src == NULL)
    return (-1);
  i = 0;
  while (*(src + i))
    {
      *(dest + i) = *(src + i);
      ++i;
    }
  *(dest + i) = *(src + i);
  return (0);
}
