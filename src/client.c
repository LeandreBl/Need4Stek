/*
** client.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 17:40:29 2017 Léandre Blanchard
** Last update Fri Jun  9 08:24:51 2017 Léandre Blanchard
*/

#include "n4s.h"

static int	connect_socket(sfTcpSocket *socket, sfIpAddress *addr)
{
  int		a;

  a = 0;
  if (my_strcmp(addr->address, "0.0.0.0") == 0)
    return (-1);
  while ((sfTcpSocket_connect(socket, *addr, PORT, sfSeconds(10)))
	 != sfSocketDone && a < 10000)
    a++;
  if (a >= 10000)
    {
      mprintf("%sCan't connect to %s%s%s <Timedout>\n%s",
		BOLDRED, BOLDCYAN, addr->address, BOLDRED, RESET);
      return (-1);
    }
  sfTcpSocket_setBlocking(socket, sfFalse);
  return (0);
}

static int	display(t_window *window, t_texture *textures,
			t_player *players)
{
  static int    a;
  int           i;
  static int    alt = 1;
  int           kart;

  i = 1;
  put_sprite(window, SPRITE(LOBBY), ORIGIN);
  put_sprite_resize(window, textures->karts[players[0].info->skin][a / 30],
		    XY(W_2 - 115, H_2 - 115), XY(7, 7));
  put_word(players[0].info->name, XY(W_2 - 65, H_2 - 155), window, sfWhite);
  while (i < MAX_PLAYERS)
    {
      if ((kart = players[i].info->skin) > -1
	  && players[i].info->status > -1)
	{
	  put_sprite_resize(window, textures->karts[kart][5],
			    XY(100 + i * 150, H_2 + 200), XY(3, 3));
	  put_word(players[i].info->name,
		   XY(100 + i * 150, H_2 + 100), window, sfBlack);
	}
      i++;
    }
  alt =(a == 0) ? 1 : (a == 300) ? 0 : alt;
  a = (alt == 1) ? (a + 1) : (a - 1);
  return (0);
}

int		client(t_window *window, t_texture *textures,
		       t_player *players, sfIpAddress addr)
{
  sfThread	*thread;

  if ((connect_socket(players[0].socket, &addr)) != 0)
    return (-1);
  thread = sfThread_create((void *)sockets_manager_client, (void *)players);
  sfThread_launch(thread);
  while (sfRenderWindow_isOpen(window->window)
	 && players[1].info->status != 1)
    {
      window_clear(window);
      display(window, textures, players);
      close_win(window);
      window_refresh(window);
    }
  if (players[1].info->status == 1)
    ingame_client(window, textures, players);
  players[0].info->status = -1;
  usleep(2000);
  free_thread(thread);
  return (0);
}
