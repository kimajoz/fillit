/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:36:44 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/09 15:49:16 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include "struct.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUF_SIZE 527

int		get_square_root(int nombrepieces);
int		check_usage(int argc, char **argv, int nombrepieces);
char	*openfile(char *filename);
int		filter_file(char *my_block, int i, int car, int ligne);
char	**checkfile(char *filecontent, int *blocknumb);
int		**create_all_tetriminos(char **filecontent, int blocknumb);
char	**ft_createmap(int mapsize);
int		ft_showmap(char **map);
int		resolvesquare(int ***all_tetriminos, int nombrepieces, int numeropiece,
		t_map *map);
int		resolve_smallest_square(int **all_tetriminos,
		int nombrepieces, int mapsize);

#endif
