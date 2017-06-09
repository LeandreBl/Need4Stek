/*
** thread.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 17:29:23 2017 Léandre Blanchard
** Last update Mon Jun  5 14:28:16 2017 Léandre Blanchard
*/

#include "n4s.h"

void		spam_receive(t_player *players)
{
  while (players[0].info->status >= 0)
    {
      if (players[0].info->status != 4)
	{
	  host_receive(players);
	  usleep(2000);
	}
    }
}

void		spam_send(t_player *players)
{
  while (players[0].info->status >= 0)
    {
      if (players[0].info->status != 4)
	{
	  host_send(players);
	  usleep(2000);
	}
    }
}

void		sockets_manager_host(t_player *players)
{
  sfThread	*send;
  sfThread	*receive;

  if ((send = sfThread_create((void *)spam_send,
			      (void *)players)) == NULL
      || (receive = sfThread_create((void *)spam_receive,
				    (void *)players)) == NULL)
    my_printf("Failed to initialize threads :/\n");
  sfThread_launch(send);
  sfThread_launch(receive);
}

void		sockets_manager_client(t_player *players)
{
  while (players[0].info->status >= 0)
    {
      if (players[1].info->status != 4)
	{
	  client_receive(players);
	  usleep(1000);
	  client_send(&players[0]);
	  usleep(1000);
	}
    }
}
