# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talkhati <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 14:25:04 by talkhati          #+#    #+#              #
#    Updated: 2026/01/01 14:25:10 by talkhati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_1 = server
NAME_2= client
NAME_3 = server_bonus
NAME_4 = client_bonus

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c
SRC_SERVER_bonus = server_bonus.c utils_bonus.c
SRC_CLIENT_bonus = client_bonus.c utils_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_bonus = $(SRC_SERVER_bonus:.c=.o)
OBJ_CLIENT_bonus = $(SRC_CLIENT_bonus:.c=.o)

all: $(NAME_1) $(NAME_2)
bonus: $(NAME_3) $(NAME_4)

$(NAME_1): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_1)

$(NAME_2): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_2)

$(NAME_3): $(OBJ_SERVER_bonus)
	$(CC) $(CFLAGS) $(OBJ_SERVER_bonus) -o $(NAME_3)

$(NAME_4): $(OBJ_CLIENT_bonus)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_bonus) -o $(NAME_4)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_bonus) $(OBJ_CLIENT_bonus)

fclean: clean
	rm -f $(NAME_1) $(NAME_2) $(NAME_3) $(NAME_4)

re: fclean all

.PHONY: all clean fclean re
