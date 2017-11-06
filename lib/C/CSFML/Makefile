##
## EPITECH PROJECT, 2017
## lib csfml
## File description:
## makefile
##

NAME	= ../libmy_csfml.a

LIBC	= ../libdefault.a

CC	= gcc

MAKE	= make -C

ARCH	= ar

SRCS	= clear_win.c
SRCS	+= free.c
SRCS	+= create_sprite.c
SRCS	+= init_csfml.c
SRCS	+= get_pixel_color.c
SRCS	+= in_rect.c
SRCS	+= key_released.c
SRCS	+= mouse_pos.c
SRCS	+= my_put_pixel.c
SRCS	+= my_put_png.c
SRCS	+= my_put_sphere.c
SRCS	+= put_square.c
SRCS	+= put_text.c
SRCS	+= quit.c
SRCS	+= thread.c
SRCS	+= xy_vect.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	= -W -Werror -fPIC -g3 -Wall -Wextra -I ..

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) ../default
	$(ARCH) rcT $(NAME) $(LIBC) $(OBJS)

clean:
	$(MAKE) ../default clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) ../default fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
