# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbillett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 16:12:19 by pbillett          #+#    #+#              #
#    Updated: 2016/02/26 18:10:57 by pbillett         ###   ########.fr        #
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
# 	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) $(LIB)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) -L . -lft

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
