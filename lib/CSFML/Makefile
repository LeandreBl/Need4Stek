##
## Makefile for  in /home/vatoth/Epitech/CPE_2016_n4s/bonus/lib/CSFML
## 
## Made by 
## Login   <quentin.sonnefraud@epitech.eu>
## 
## Started on  Wed May 31 14:16:09 2017 
## Last update Wed May 31 15:35:01 2017 
##

NAME    = lib_my_csfml.a

SRCS    =  $(wildcard srcs/*.c)

OBJS    = $(SRCS:.c=.o)

RM      = rm -f

SHARED_LIB = libc_graph_prog_full.so

LIB = -lc_graph_prog_full

CFLAGS  += -Wall -Wextra -Werror 

CPPFLAGS += -I./include

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ar crs $(NAME) $(SHARED_LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
