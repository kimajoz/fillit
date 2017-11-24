/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/09 15:50:20 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

static char		**ft_addblock(int *piece, int n, t_map *map, t_pos pos)
{
	int			m;
	t_pos		p;
	t_pos		carte;

	carte.y = 0;
	m = 0;
	piece = ft_addoffset_to_piece(piece, pos.y, pos.x);
	p.y = piece[m++];
	p.x = piece[m++];
	while (carte.y < map->size)
	{
		carte.x = 0;
		while (carte.x < map->size)
		{
			if (carte.y == p.y && carte.x == p.x && m <= 8)
			{
				map->map[carte.y][carte.x] = 'A' + n;
				p.y = piece[m++];
				p.x = piece[m++];
			}
			carte.x++;
		}
		carte.y++;
	}
	return (map->map);
}

static int		ft_checkaddblock(int *piece, t_map map, int offset_y,
		int offset_x)
{
	int			i;

	i = 0;
	while (i < 8)
	{
		if (((piece[i] + offset_y) >= map.size) ||
				((piece[i + 1] + offset_x) >= map.size))
			return (0);
		i = i + 2;
	}
	if ((map.map)[(piece[0] + offset_y)][(piece[1] + offset_x)] == '#' ||
	(map.map)[(piece[2] + offset_y)][(piece[3] + offset_x)] == '#' ||
	(map.map)[(piece[4] + offset_y)][(piece[5] + offset_x)] == '#' ||
	(map.map)[(piece[6] + offset_y)][(piece[7] + offset_x)] == '#')
		return (0);
	if ((map.map)[(piece[0] + offset_y)][(piece[1] + offset_x)] == '.' &&
	(map.map)[(piece[2] + offset_y)][(piece[3] + offset_x)] == '.' &&
	(map.map)[(piece[4] + offset_y)][(piece[5] + offset_x)] == '.' &&
	(map.map)[(piece[6] + offset_y)][(piece[7] + offset_x)] == '.')
	{
		return (1);
	}
	return (0);
}

int				resolvesquare(int ***all_tetriminos, int totpieces,
		int n, t_map *map)
{
	t_pos		pos;

	pos.y = 0;
	while (pos.y < map->size)
	{
		pos.x = 0;
		while (pos.x < map->size)
		{
			if (ft_checkaddblock((*all_tetriminos)[n], *map,
						pos.y, pos.x) == 1)
			{
				ft_addblock((*all_tetriminos)[n], n, map, pos);
				if (n == ((totpieces) - 1))
					return (1);
				if (resolvesquare(all_tetriminos, totpieces, n + 1, map) == 0)
					ft_removeblock(n, &map->map, map->size);
				else
					return (1);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
