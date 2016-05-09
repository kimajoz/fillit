# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbillett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 16:12:19 by pbillett          #+#    #+#              #
#    Updated: 2016/05/09 20:35:55 by pbillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c \
		get_square_root.c \
		check_usage.c \
		openfile.c \
		filter_file.c \
		checkfile.c \
		create_all_tetriminos.c \
		createshow_map.c \
		resolvesquare.c \
		resolve_smallest_square.c
LIB = -L ./libft -lft
FLAG = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(SRC)
	make -C libft
	gcc $(FLAG) -o $(NAME) $(SRC) $(LIB)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: re fclean clean all
