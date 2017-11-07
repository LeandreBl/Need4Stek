/*
** listener.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 16:55:48 2017 Léandre Blanchard
** Last update Tue Nov  7 01:20:36 2017 Léandre Blanchard
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
  sfIpAddress	addr;
  char		*address;
  int		a;
  int		i;

  a = 0;
  i = 1;
  address = get_ip(NULL);
  memcopy(addr.address, address, my_strlen(address));
  free(address);
  if ((listener = sfTcpListener_create()) == NULL)
    return (-1);
  if (sfTcpListener_listen(listener, PORT, addr) == sfSocketError)
    players[0].info->status = -2;
  while (i < MAX_PLAYERS && i != -1 && players[0].info->status != -2)
    {
      if (sfTcpListener_accept(listener, &players[i].socket) == sfSocketDone)
	{
	  if ((a = first_inactive_player(players)) == -1)
	    return (-1);
	  sfTcpSocket_setBlocking(players[i].socket, sfFalse);
	  mprintf("%sPlayer n°%d connected%s\n", BOLDGREEN, a + 1, RESET);
	  i++;
	}
      if (i > MAX_PLAYERS)
	i = first_inactive_player(players);
    }
  return (0);
}
