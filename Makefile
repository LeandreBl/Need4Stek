##
## Makefile for *** in /home/leandre/***
## 
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
## 
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Tue Nov  7 01:21:10 2017 Léandre Blanchard
##

NAME	= tek_kart

CC	= gcc

MAKE	= make -j 8 -C

LIB	= -L./lib/C -lmy
LIB	+= -L./lib/CSFML -lmy_csfml
LIB	+= -lcsfml-network -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system
LIB	+= -lX11
LIB	+= -lm

SRCS	= src/main.c
SRCS	+= src/init_textures.c
SRCS    += src/init_players.c
SRCS    += src/select_map.c
SRCS    += src/init_musics.c
SRCS    += src/free.c
SRCS    += src/open_karts.c
SRCS    += src/bg_video.c
SRCS    += src/time.c
SRCS    += src/lobby.c
SRCS    += src/gogoby.c
SRCS    += src/send_map.c
SRCS    += src/listener.c
SRCS    += src/accelerator.c
SRCS    += src/can_see.c
SRCS    += src/disp_preview.c
SRCS    += src/send.c
SRCS    += src/receive.c
SRCS    += src/thread.c
SRCS    += src/client.c
SRCS    += src/ingame_host.c
SRCS    += src/ingame_client.c
SRCS    += src/raycast.c
SRCS    += src/moves.c
SRCS    += src/load_map.c
SRCS    += src/load_sprites.c
SRCS    += src/select_texture.c
SRCS    += src/display_ingame.c
SRCS    += src/display_players.c
SRCS    += src/inertial.c
SRCS    += src/motor_sound.c
SRCS    += src/signal.c
SRCS    += src/minimap.c

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

CPPFLAGS += -I ./include

CFLAGS	+= -W -Wall -Wextra -O3

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) lib/C
	$(MAKE) lib/C/CSFML
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(MAKE) lib/C clean
	$(MAKE) lib/C/CSFML clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) lib/C fclean
	$(MAKE) lib/C/CSFML fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
