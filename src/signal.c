/*
** signal.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May  5 19:13:18 2017 Léandre Blanchard
** Last update Fri May  5 23:11:10 2017 Léandre Blanchard
*/

#include "n4s.h"

void		sigquit_handler(int sig)
{
  static int	status;

  if (status == 1)
    exit(84);
  if (sig == SIGINT)
    {
      mprintf("Press Escape to quit\n");
      status = 1;
    }
}
