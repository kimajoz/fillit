/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createshow_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:42:01 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/10 14:05:43 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_createmap(int mapsize)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = (char **)malloc(mapsize * sizeof(char *));
	while (y < mapsize)
	{
		x = 0;
		map[y] = (char *)malloc(mapsize * sizeof(char));
		while (x < mapsize)
			map[y][x++] = '.';
		y++;
	}
	return (map);
}

int			ft_showmap(char **map, int mapsize)
{
	int		i;
	int		j;

	j = 0;
	while (j < mapsize)
	{
		i = 0;
		while (i < mapsize)
		{
			ft_putchar(map[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return (0);
}
