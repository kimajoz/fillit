/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:36:44 by pbillett          #+#    #+#             */
/*   Updated: 2016/03/04 16:27:09 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUF_SIZE 527

char	*openfile(char* filename);
char	**checkfile(char* filecontent, int *blocknumb);
int		**create_all_tetriminos(char **filecontent, int blocknumb);
int		resolvesquare(int **filecontent, int blocknumb, int mapsize, int numpiece_actuelle);

#endif
