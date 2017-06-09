/*
** thread.c for thread in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 27 19:03:37 2017 Léandre Blanchard
** Last update Thu Jun  1 15:35:57 2017 Léandre Blanchard
*/

#include "csfml.h"

void            free_thread(sfThread *thread)
{
  usleep(2000);
  sfThread_terminate(thread);
  sfThread_destroy(thread);
}
