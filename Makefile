# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbillett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 16:12:19 by pbillett          #+#    #+#              #
#    Updated: 2016/06/22 15:13:51 by pbillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC =	src/ft_putchar.c \
		src/ft_putnbr.c \
		src/ft_putstr.c \
		src/ft_memalloc.c \
		src/ft_bzero.c \
		src/main.c \
		src/get_square_root.c \
		src/check_usage.c \
		src/openfile.c \
		src/filter_file.c \
		src/checkfile.c \
		src/create_all_tetriminos.c \
		src/createshow_map.c \
		src/resolvesquare.c \
		src/resolve_smallest_square.c
FLAG = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(SRC)
	gcc $(FLAG) -o $(NAME) $(SRC)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: re fclean clean all
