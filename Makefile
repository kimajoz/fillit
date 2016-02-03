# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbillett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 16:12:19 by pbillett          #+#    #+#              #
#    Updated: 2016/02/03 16:34:58 by pbillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c \
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
