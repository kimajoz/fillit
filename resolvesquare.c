/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/02 19:45:41 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*ft_addoffset_to_piece(int *piece, int offset_y, int offset_x)
{
	int			i;
	int			*newpiece;

	i = 0;
	newpiece = malloc(8 * sizeof(int));
	if (newpiece == NULL)
		return (NULL);
	while (i < 8)
	{
		newpiece[i] = piece[i] + offset_y;
		newpiece[i + 1] = piece[i + 1] + offset_x;
		i = i + 2;
	}
	return (newpiece);
}

static char		**ft_removeblock(int pieceasupprimer, char ***map, int mapsize)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < mapsize)
	{
		i = 0;
		while (i < mapsize)
		{
			if ((*map)[j][i] == ('A' + pieceasupprimer))
				(*map)[j][i] = '.';
			i++;
		}
		j++;
	}
	return (*map);
}

static char		**ft_addblock(int *piece, int numeropiece,
		char ***map, int mapsize, int offset_y, int offset_x)
{
	int			i;
	int			j;
	int			x;
	int			y;
	int			m;

	j = 0;
	m = 0;
	piece = ft_addoffset_to_piece(piece, offset_y, offset_x);
	y = piece[m++];
	x = piece[m++];
	while (j < mapsize)
	{
		i = 0;
		while (i < mapsize)
		{
			if (j == y && i == x && m <= 8)
			{
				(*map)[j][i] = 'A' + numeropiece;
				y = piece[m++];
				x = piece[m++];
			}
			i++;
		}
		j++;
	}
	return (*map);
}

static int		ft_checkaddblock(int *piece, char ***map,
		int mapsize, int offset_y, int offset_x)
{
	int			i;

	i = 0;
	while (i < 8)
	{
		if (((piece[i] + offset_y) >= mapsize) ||
				((piece[i + 1] + offset_x) >= mapsize))
			return (0);
		i = i + 2;
	}
	if ((*map)[(piece[0] + offset_y)][(piece[1] + offset_x)] == '#' ||
	(*map)[(piece[2] + offset_y)][(piece[3] + offset_x)] == '#' ||
	(*map)[(piece[4] + offset_y)][(piece[5] + offset_x)] == '#' ||
	(*map)[(piece[6] + offset_y)][(piece[7] + offset_x)] == '#')
		return (0);
	if ((*map)[(piece[0] + offset_y)][(piece[1] + offset_x)] == '.' &&
	(*map)[(piece[2] + offset_y)][(piece[3] + offset_x)] == '.' &&
	(*map)[(piece[4] + offset_y)][(piece[5] + offset_x)] == '.' &&
	(*map)[(piece[6] + offset_y)][(piece[7] + offset_x)] == '.')
	{
		return (1);
	}
	return (0);
}

int				resolvesquare(int ***all_tetriminos, int nombrepieces,
		char **map, int piece, int mapsize)
{
	int			x;
	int			y;

	y = 0;
	while (y < mapsize)
	{
		x = 0;
		while (x < mapsize)
		{
			if (ft_checkaddblock((*all_tetriminos)[piece], &map,
						mapsize, y, x) == 1)
			{
				ft_addblock((*all_tetriminos)[piece], piece,
						&map, mapsize, y, x);
				if (piece == (nombrepieces - 1))
					return (1);
				if (resolvesquare(all_tetriminos, nombrepieces, map,
							piece + 1, mapsize) == 0)
					ft_removeblock(piece, &map, mapsize);
				else
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
