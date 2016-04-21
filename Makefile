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
		createshow_map.c \
		resolvesquare.c \
		resolve_smallest_square.c
LIB = libft.a

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) $(LIB)
	#gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) -L .  #Autre technique
#Pour linux rien à modifier. Penser juste à bien recompiler la librairie utiliser sous linux. (ex: ici libft.a) Voila ! :) Enjoy !

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

libs: libft

libft:
	( cd ../libft/ && make re && cp libft.a ../fillit/; )

reall: libft re

exec:
	./fillit small_extern_file.txt

reallexec: reall exec
