/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createshow_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:42:01 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/02 18:46:48 by pbillett         ###   ########.fr       */
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

int			ft_showmap(char **map, int mapsize)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < mapsize)
	{
		while (i < mapsize)
			ft_putchar(map[j][i++]);
		ft_putchar('\n');
		i = 0;
		j++;
	}
	return (0);
}
