/*
** in_game_host.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 12:29:27 2017 Léandre Blanchard
** Last update Tue Jun  6 14:22:56 2017 Léandre Blanchard
*/

#include "n4s.h"

void			init_music_properly(t_window *window)
{
  sfMusic_setLoop(window->musics[0], sfTrue);
  sfMusic_setLoop(window->musics[1], sfTrue);
  sfMusic_setLoop(window->musics[3], sfTrue);
  sfMusic_play(window->musics[0]);
  sfMusic_play(window->musics[3]);
  sfMusic_setVolume(window->musics[3], 0);
  sfMusic_setVolume(window->musics[0], 30);
}

void			special_refresh(t_window *window, t_texture *textures)
{
  sfTexture_updateFromPixels(window->texture, window->pixels,
			     window->width, window->height, 0, 0);
  sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
  put_sprite_resize(window, textures->smap, ORIGIN, XY(7, 7));
}

int			somedisplay(t_window *window, t_texture *textures,
			    t_player *players, float speed)
{
  char			*disp;

  special_refresh(window, textures);
  display_players(window, textures, players);
  display_me(window, textures, players, speed);
  if ((disp = my_calloc(my_intlen(timer.time * 10))) == NULL)
    return (-1);
  sprintf(disp, "%d min %d sec", (int)timer.time / 60, (int)timer.time % 60);
  put_word(disp, XY(10, H_ - 40), window, sfWhite);
  free(disp);
  sfRenderWindow_display(window->window);
  return (0);
}

int			ingame_host(t_window *window, t_texture *textures,
				    t_player *players)
{
  float			speed;

  send_map(textures->map, players);
  players[0].info->pos = player_start(textures->map);
  if (init_minimap(textures) == -1)
    return (-1);
  while (sfRenderWindow_isOpen(window->window))
    {
      window_clear(window);
      close_win(window);
      speed = move_me(textures->map, &players[0]);
      vary_motor(window->musics[1], speed);
      display_background(window, textures, players[0].info->dir);
      walls(window, textures->map, textures, &players[0]);
      minimap(textures, players, textures->map);
      somedisplay(window, textures, players, speed);
      wait_music(window);
    }
  sfMusic_stop(window->musics[0]);
  free_tab(textures->map);
  return (0);
}
