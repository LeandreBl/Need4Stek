/*
** listener.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 16:55:48 2017 Léandre Blanchard
** Last update Tue May 30 19:50:38 2017 Léandre Blanchard
*/

#include "n4s.h"

int		first_inactive_player(t_player *players)
{
  int		i;

  i = 1;
  while (i < MAX_PLAYERS)
    {
      if (my_strlen(players[i].info->name) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int		listener(t_player *players)
{
  sfTcpListener	*listener;
  int		a;
  int		i;

  a = 0;
  i = 1;
  if ((listener = sfTcpListener_create()) == NULL)
    return (-1);
  if (sfTcpListener_listen(listener, PORT) == sfSocketError)
    players[0].info->status = -2;
  while (i < MAX_PLAYERS && i != -1 && players[0].info->status != -2)
    {
      if (sfTcpListener_accept(listener, &players[i].socket) == sfSocketDone)
	{
	  if ((a = first_inactive_player(players)) == -1)
	    return (-1);
	  sfTcpSocket_setBlocking(players[i].socket, sfFalse);
	  my_printf("%sPlayer n°%d connected%s\n", BOLDGREEN, a + 1, RESET);
	  i++;
	}
      if (i > MAX_PLAYERS)
	i = first_inactive_player(players);
    }
  return (0);
}
