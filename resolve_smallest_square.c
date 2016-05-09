/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_smallest_square.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 19:07:40 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/09 16:07:21 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**increase_mapsize(char **map, int mapsize)
{
	int			m;

	m = 0;
	while (m < (mapsize - 1))
	{
		free(map[m]);
		m++;
	}
	free(map);
	m = 0;
	mapsize++;
	map = ft_createmap(mapsize);
	return (map);
}

int				resolve_smallest_square(int **all_tetriminos,
		int nombrepieces, int mapsize)
{
	int			n;
	t_map		map;

	n = 0;
	map.map = ft_createmap(mapsize);
	map.size = mapsize;
	while (resolvesquare(&all_tetriminos, nombrepieces, n, &map) != 1)
		map.map = increase_mapsize(map.map, map.size++);
	ft_showmap(map.map);
	return (0);
}
