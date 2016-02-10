# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbillett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 16:12:19 by pbillett          #+#    #+#              #
#    Updated: 2016/02/10 14:02:59 by pbillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c \
		openfile.c \
		checkfile.c \
		resolvesquare.c
LIB = libft.a

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) $(LIB)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
