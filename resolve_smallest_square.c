/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_smallest_square.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 19:07:40 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/02 19:46:02 by pbillett         ###   ########.fr       */
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
	char		**map;

	n = 0;
	map = ft_createmap(mapsize);
	while (resolvesquare(&all_tetriminos, nombrepieces, map, n, mapsize) != 1)
		map = increase_mapsize(map, mapsize++);
	ft_showmap(map, mapsize);
	return (0);
}
