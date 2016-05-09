/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createshow_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:42:01 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/09 16:07:44 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_createmap(int mapsize)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	x = 0;
	map = (char **)malloc(mapsize * sizeof(char *));
	while (y < mapsize)
	{
		map[y] = (char *)malloc(mapsize * sizeof(char));
		while (x < mapsize)
			map[y][x++] = '.';
		x = 0;
		y++;
	}
	return (map);
}

int			ft_showmap(char **map)
{
	int		i;
	int		j;
	int		mapsize;

	i = 0;
	j = 0;
	mapsize = 1;
	while (j < mapsize)
	{
		while (map[j][i])
			ft_putchar(map[j][i++]);
		ft_putchar('\n');
		mapsize = i;
		i = 0;
		j++;
	}
	return (0);
}
