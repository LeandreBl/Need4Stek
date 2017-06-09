/*
** init_players.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 13:47:49 2017 Léandre Blanchard
** Last update Sat May  6 00:39:18 2017 Léandre Blanchard
*/

#include "n4s.h"

int		fill_info(t_info *info, char *name, int skin)
{
  if (my_strcpy(info->name, name) == -1)
    zeros(info->name, NAME_SIZE);
  info->skin = skin;
  return (0);
}

t_player	*init_players(int nb)
{
  t_player	*players;
  int		i;

  i = 0;
  if ((players = malloc(sizeof(t_player) * (nb + 1))) == NULL)
    return (NULL);
  while (i != nb)
    {
      if ((players[i].info = malloc(sizeof(t_info))) == NULL)
	return (NULL);
      fill_info(players[i].info, NULL, -1);
      players[i].info->dir = 90;
      players[i].info->pos = START;
      players[i].info->status = -1;
      if ((players[i].socket = sfTcpSocket_create()) == NULL)
	return (NULL);
      i++;
    }
  players[0].info->status = 0;
  return (players);
}
