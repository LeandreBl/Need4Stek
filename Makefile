##
## Makefile for *** in /home/leandre/***
## 
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
## 
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Wed Nov  1 20:27:20 2017 Léandre Blanchard
##

NAME	= tek_kart

CC	= gcc

MAKE	= make -C

LIB	= -L./lib/C -lmy
LIB	+= -L./lib/CSFML -lmy_csfml
LIB	+= -lc_graph_prog_full
LIB	+= -lX11
LIB	+= -lm

SRCS	= src/main.c \
	  src/init_textures.c \
	  src/init_players.c \
	  src/select_map.c 	\
	  src/init_musics.c \
	  src/free.c \
	  src/open_karts.c \
	  src/bg_video.c \
	  src/time.c \
	  src/lobby.c \
	  src/gogoby.c \
	  src/send_map.c \
	  src/listener.c \
	  src/accelerator.c \
	  src/can_see.c \
	  src/disp_preview.c \
	  src/send.c \
	  src/receive.c \
	  src/thread.c \
	  src/client.c \
	  src/ingame_host.c \
	  src/ingame_client.c \
	  src/raycast.c \
	  src/moves.c \
	  src/load_map.c \
	  src/load_sprites.c \
	  src/select_texture.c \
	  src/display_ingame.c \
	  src/display_players.c \
	  src/inertial.c \
	  src/motor_sound.c \
	  src/signal.c \
	  src/minimap.c

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
