/*
** my_free.c for fere in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 24 16:35:59 2017 Léandre Blanchard
** Last update Wed May 24 16:36:53 2017 Léandre Blanchard
*/

#include <stdlib.h>

void		my_free(void *ptr)
{
  if (ptr != NULL)
    {
      free(ptr);
      ptr = NULL;
    }
}
