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
SRC = ft_putchar.c \
	  	ft_putnbr.c \
	  	ft_putstr.c \
		ft_memalloc.c \
		ft_bzero.c \
		main.c \
		get_square_root.c \
		check_usage.c \
		openfile.c \
		filter_file.c \
		checkfile.c \
		create_all_tetriminos.c \
		createshow_map.c \
		resolvesquare.c \
		resolve_smallest_square.c
FLAG = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(SRC)
	gcc $(FLAG) -o $(NAME) $(SRC)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: re fclean clean all
