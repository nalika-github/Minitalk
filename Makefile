# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 13:50:38 by ptungbun          #+#    #+#              #
#    Updated: 2023/04/09 14:43:18 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
SERVNAME	=	server
CLINNAME	=	client
HEADER		=	minitalk.h
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

# Note the single quotes the * exoressions. Make will incorrectly expand these otherwise.

SERV		=	server.c
CLIN		=	client.c
SRCS		=	ft_atoi.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c

all: $(NAME)

# Build step for C source

$(NAME): client server

client:
	$(CC) $(CFLAGS) $(SRCS) $(CLIN) -o $(CLINNAME)

server:
	$(CC) $(CFLAGS) $(SRCS) $(SERV) -o $(SERVNAME)

clean:
	rm -rf $(SERVNAME) $(CLINNAME)

fclean:
	rm -rf $(SERVNAME) $(CLINNAME)

re: fclean all

.PHONY: all clean fclean re
