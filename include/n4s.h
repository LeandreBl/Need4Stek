/*
** n4s.h for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May  2 18:25:26 2017 Léandre Blanchard
** Last update Wed Nov  1 17:25:51 2017 Léandre Blanchard
*/

#ifndef N4S_H_
# define N4S_H_

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>

# include "my.h"
# include "colors.h"
# include "defines.h"
# include "my_csfml.h"

# define DIST_ 0.01
# define NAME_SIZE 20
# define FOV 90
# define ROLL 3 - speed / 40
# define ACCELERATION 1.1
# define ROLL_ACCELERATION 1.05
# define MAX_SPEED 20
# define PDIR players[0].info->dir
# define MOVEX speed / 100 * cos(M_PI / 180.0 * info->dir)
# define MOVEY speed / 100 * sin(M_PI / 180.0 * info->dir)
# define WALLX 0.7 * cos(M_PI / 180.0 * info->dir)
# define WALLY 0.7 * sin(M_PI / 180.0 * info->dir)
# define TRACEX 10 * cos(M_PI / 180.0 * (PDIR - FOV / 2))
# define TRACEY 10 * sin(M_PI / 180.0 * (PDIR - FOV / 2))
# define PROJX(x) x * cos(M_PI / 180.0 * angle)
# define PROJY(y) y * sin(M_PI / 180.0 * angle)
# define TESTX 10 * cos(M_PI / 180.0 * dir_dist.y)
# define TESTY 10 * sin(M_PI /180.0 * dir_dist.y)
# define ANGL angle(players[0].info->pos, players[i].info->pos
# define PROJ window->width / 2 * tan(30 * M_PI / (180 - FOV * 2 / 3))
# define TEXTURE_SIZE 64
# define USAGE1 "%s./tek_kart --join [ip_address] [nickname]%s%s\n"
# define USAGE2 "\n./tek_kart --server [nickname]"
# define SEND_ERR "%sPacket missed %s%d%s bytes in send :/%s\n"
# define PATH_IMAGES "images/wall"
# define NB_IMAGES 3
# define NB_KARTS 6
# define NB_SPRITES 7
# define NB_SOUNDS 4
# define KART_FOUND "%sSprites of kart in %s%s%s loaded\n%s"
# define PLAYER_DC "%sPlayer n°%d left the game\n%s"
# define KART_FOLDER "karts/"
# define SPRITES_FOLDER "sprites/"
# define SPRITE_FOUND "%sSprite ingame : %s%s%s loaded\n%s"
# define MUSIC_FOUND "%sSound %s%s%s found and loaded\n%s"
# define MAX_PLAYERS 8
# define MISSING_SPRITES "%sMissing sprites in ./sprites or ./karts :( %s\n"
# define BOX_ "%so----------------------------------------------------o%s\n"
# define XY(x, y) xy_vectorf(x, y)
# define XYI(x, y) xy_vectori(x, y)
# define ORIGIN xy_vectorf(0, 0)
# define H_ window->height
# define W_ window->width
# define H_2 window->height / 2
# define W_2 window->width / 2
# define Y_IP "\n%sYour Local ip is : %s%s%s\nYour Public ip is : %s%s%s\n"
# define PORT 4697
# define LOBBY 0
# define BUTTON 1
# define BUTTON_PRESSED 2
# define CLOUDS 3
# define ROAD 4
# define SPEEDOMETER 5
# define START xy_vectorf(4, 4)
# define SPRITE(x) textures->sprites[x]
# define MAP_FOLDER "maps/"
# define MAP_PATH "maps/basic.n4s"

typedef struct	s_trigo
{
  float		dist;
  sfVector2f	point;
  float		ang;
  int		from;
}		t_trigo;

typedef struct	s_preview
{
  char		*name;
  char		**current;
  sfUint8	*pixels;
  t_sprite	*preview;
}		t_preview;

typedef struct	s_rot
{
  sfVector2i	pos;
  float		angle;
}		t_rot;

typedef struct	s_cast
{
  float		dist;
  int		texture;
  float		wall_h;
  int		change;
  float		x;
}		t_cast;

typedef struct	s_texture
{
  sfImage	**images;
  t_sprite	***karts;
  t_sprite	**sprites;
  t_sprite	**lakitu;
  sfUint8	*pmap;
  t_sprite	*smap;
  char		**map;
}		t_texture;

typedef struct	s_info
{
  int		status;
  char		name[NAME_SIZE];
  sfVector2f	pos;
  int		skin;
  float		dir;
}		t_info;

typedef struct	s_player
{
  t_info	*info;
  sfTcpSocket	*socket;
}		t_player;

typedef struct	s_minimap
{
  int		width;
  int		height;
  sfColor	color;
}		t_minimap;

typedef struct	s_time
{
  time_t	start;
  time_t	end;
  double	time;
}		t_time;

t_time		timer;

int		accelerator(t_window *window, float speed);

float		distance(sfVector2f from, sfVector2f to);

void		init_time(t_time *time);

void		update_time(t_time *time);

int		clear_map(char **map);

int		can_see(sfVector2f from, sfVector2f to, char **map);

void		bg_video(t_window *window, t_sprite **video);

t_sprite	**create_videomode(const char *pathname);

char		**recup_karts(const char *pathname);

int		send_map(char **map, t_player *players);

char		**receive_map(t_player *players);

int		init_preview(t_preview *prev);

int		put_mini_pixel(sfUint8 *pixels, int x, int y, t_minimap info);

sfColor		select_color(char **map, int i, int j);

int		preview(t_preview *prev);

int		display_preview(t_window *window,
				char **map_name, t_preview *prev);

int		reload(char **map_name, int i, t_preview *prev);

int		swap_map(char **map_name, t_preview *prev, int *from);

char		**select_map(t_window *window, sfMusic *music);

int		fill_karts(t_sprite **sprites, const char *s);

int		all_karts(t_sprite ***sprites);

int		display_players(t_window *window, t_texture *textures,
				t_player *players);

int		somedisplay(t_window *window, t_texture *textures,
			    t_player * players, float speed);

sfMusic		**init_musics(void);

int		wait_music(t_window *window);

int		all_sprites(t_sprite **sprites);

float		move_me(char **map, t_player *player);

void		sigquit_handler(int sig);

int		mv_up(t_info *info, char **map, float speed);

int		ingame_host(t_window *window, t_texture *textures,
			    t_player *players);

int		ingame_client(t_window *window, t_texture *textures,
			      t_player *players);

char		**load_map(const char *pathname);

int		init_minimap(t_texture *textures);

int		minimap(t_texture *texture, t_player *players,
			char **map);

void		init_music_properly(t_window *window);

void		inertial(float *speed);

t_texture	*init_textures(void);

void		free_textures(t_texture *textures);

void		free_players(t_player *players);

int		client(t_window *window, t_texture *textures,
		       t_player *players, sfIpAddress addr);

sfVector2f	player_start(char **map);

void		display_me(t_window *window, t_texture *textures,
			   t_player *players, float speed);

void		display_background(t_window *window,
				   t_texture *textures, float dir);

void		special_clear(t_window *window);

void		special_refresh(t_window *window, t_texture *textures);

int		change(sfVector2f ray, sfVector2f prev, int *change, float *dist);

int		select_texture(char c);

int		lobby(t_window *window, t_texture *textures, t_player *players);

t_player	*init_players(int nb);

t_sprite	**lakitu(void);

int		listener(t_player *players);

void		host_send(t_player *players);

void		client_send(t_player *player);

void		walls(t_window *window, char **map, t_texture *textures,
		      t_player *player);

void		host_receive(t_player *players);

int		client_receive(t_player *players);

void		sockets_manager_host(t_player *players);

void		sockets_manager_client(t_player *players);

int		first_inactive_player(t_player *players);

void		vary_motor(sfMusic *motor, float speed);

#endif /* !N4S_H_ */
