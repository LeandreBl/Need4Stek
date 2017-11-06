/*
** receive.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 17:24:53 2017 Léandre Blanchard
** Last update Tue May  9 15:05:05 2017 Léandre Blanchard
*/

#include "n4s.h"

static int	update_info(t_info *info, t_info new)
{
  my_strcpy(info->name, new.name);
  info->skin = new.skin;
  info->pos = XY(new.pos.x, new.pos.y);
  info->dir = new.dir;
  info->status = new.status;
  return (0);
}

void		host_receive(t_player *players)
{
  size_t	size;
  int		i;
  t_info	temp;

  i = 1;
  while (i < MAX_PLAYERS)
    {
      if ((sfTcpSocket_receive(players[i].socket,
			       &temp, sizeof(t_info),
			       &size)) == sfSocketDisconnected)
	{
	  mprintf(PLAYER_DC, BOLDBLUE, i + 1, RESET);
	  zeros(players[i].info->name, NAME_SIZE);
	  players[i].info->status = -1;
	  sfTcpSocket_destroy(players[i].socket);
	  players[i].socket = sfTcpSocket_create();
	}
      if (size == sizeof(t_info))
	update_info(players[i].info, temp);
      i++;
    }
}

int		client_receive(t_player *players)
{
  static int	next = 1;
  int		i;
  size_t	size;
  t_info	temp;

  i = 0;
  if (players[0].info->status < 0)
    return (-1);
  if ((sfTcpSocket_receive(players[0].socket, &temp, sizeof(t_info),
			   &size)) == sfSocketDisconnected)
    players[0].info->status = -2;
  if (size != sizeof(t_info))
    return (-1);
  while (i < MAX_PLAYERS && players[i].info->status >= 0)
    {
      if (i > 0)
	if (my_strcmp(temp.name, players[i].info->name) == 0
	    && my_strcmp(temp.name, players[0].info->name) != 0)
	  return (update_info(players[i].info, temp));
      i++;
    }
  if (next < MAX_PLAYERS)
    update_info(players[next++].info, temp);
  return (0);
}
