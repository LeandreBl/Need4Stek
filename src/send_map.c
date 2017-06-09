/*
** send_map.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May 31 17:45:49 2017 Léandre Blanchard
** Last update Mon Jun  5 13:41:11 2017 Léandre Blanchard
*/

#include "n4s.h"

static int	all_received(t_player *players)
{
  int		i;

  i = 1;
  while (i < MAX_PLAYERS)
    {
      if (players[i].info->status == 4)
	return (1);
      i++;
    }
  my_printf("All players connected\n");
  return (0);
}

static void	host_send_map(char **map, t_player *players, sfVector2i size)
{
  int		i;
  int		j;

  i = 1;
  while (i != MAX_PLAYERS)
    {
      if (players[i].info->status >= 0)
	{
	  my_printf("Send for player <%s>\n", players[i].info->name);
	  sfTcpSocket_setBlocking(players[i].socket, sfTrue);
	  sfTcpSocket_send(players[i].socket, &size, sizeof(sfVector2i));
	  j = 0;
	  while (map[j] != NULL)
	    sfTcpSocket_send(players[i].socket, map[j++], size.x);
	  sfTcpSocket_setBlocking(players[i].socket, sfFalse);
	}
      i++;
    }
}

int		send_map(char **map, t_player *players)
{
  sfVector2i	size;
  int		i;

  i = 1;
  size = xy_vectori(my_strlen(map[0]), my_tablen(map));
  players[0].info->status = 4;
  host_send(players);
  host_send_map(map, players, size);
  players[0].info->status = 1;
  host_send(players);
  while (i < MAX_PLAYERS)
    {
      if (players[i].info->status >= 0)
	players[i].info->status = 4;
      ++i;
    }
  while (all_received(players));
  return (0);
}

static void	manage_sockets_map(t_player *players)
{
  while (players[1].info->status != 4)
    my_printf("\rHost selecting map ...");
  players[0].info->status = 4;
  my_printf("\nMap selected !\n");
  client_send(&players[0]);
  sfTcpSocket_setBlocking(players[0].socket, sfTrue);
  my_printf("Downloading map ...\n");
}

char		**receive_map(t_player *players)
{
  int		i;
  char		**map;
  sfVector2i	size;
  size_t       	rc;

  i = 0;
  size = xy_vectori(0, 0);
  manage_sockets_map(players);
  while (size.x == 0 || size.x > 100 || size.y == 0 || size.y > 100)
    if (sfTcpSocket_receive(players[0].socket, &size,
			    sizeof(sfVector2i), &rc) == sfSocketDisconnected)
    return (NULL);
  my_printf("map size : [%d, %d]\n", size.x, size.y);
  if (rc != sizeof(sfVector2i))
    return (NULL);
  if ((map = my_alloc_tab(size.y, size.x)) == NULL)
    return (NULL);
  while (i < size.y)
    if (sfTcpSocket_receive(players[0].socket, map[i++],
			    size.x, &rc) == sfSocketDisconnected
	|| (int)rc != size.x)
      return (NULL);
  sfTcpSocket_setBlocking(players[0].socket, sfFalse);
  players[1].info->status = 1;
  return (map);
}
