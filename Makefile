# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbillett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 16:12:19 by pbillett          #+#    #+#              #
#    Updated: 2016/03/02 11:25:01 by pbillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c \
		openfile.c \
		checkfile.c \
		create_all_tetriminos.c \
		resolvesquare.c
LIB = libft.a

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) $(LIB)
	#gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) -L .  #Pour linux home

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
