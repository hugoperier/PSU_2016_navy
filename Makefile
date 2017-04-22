##
## Makefile for Makefile in /home/hugo/Projet/sysUnix/PSU_2016_my_ls_bootstrap
## 
## Made by Hugo Perier
## Login   <hugo@epitech.net>
## 
## Started on  Wed Nov 23 14:20:42 2016 Hugo Perier
## Last update Sat Apr 22 10:23:34 2017 Hugo Perier
##

CC	= gcc

RM	= rm -f

NAME	= navy

SRCS	= main.c		\
	  getmap.c		\
	  connect.c		\
	  get_data.c		\
	  send_data.c		\
	  fct_all.c		\
	  get_pid_enemy.c	\
	  verif_map.c		\
	  ckeckend.c		\
	  my_strcpy.c		\
	  my_putstr.c		\
	  my_getnbr.c




OBJS	= $(SRCS:.c=.o)

LDLIB	= -lgnl

CFLAGS	=    -W -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o  $(NAME) $(OBJS) $(LDLIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
