/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/03/02 20:36:05 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_createmap(int mapsize)
{
	int y;
	int x;
	char **map;

	y = 0;
	x = 0;
	ft_putstr("Je cree la map\n");
	map = (char **)malloc(mapsize * sizeof(char *));
	while (y < mapsize)
	{
		map[y] = (char *)malloc(mapsize * sizeof(char));
		while(x < mapsize)
		{
			map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	return(map);
}

static int		ft_showmap(char **map, int mapsize)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr("I show the map : \n\n");

	while (j < mapsize)
	{
		while (map[j][i] != '\0')
		{
			ft_putchar(map[j][i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
	return (0);
}

static char		**ft_addblock(int *piece, char ***map, int mapsize, int offset)
{
	int i;
	int j;
	int x;
	int y;
	int m;

	j = 0;
	m = 0;

	/*
	if (offset != 0) // Si il y a un offset mettre a jour toutes les coordonnees
	while (piece[i] != '\0')
	{
		piece[i] = piece[i] + offset;
		i++;
	}
	i = 0;
	*/
	ft_putnbr(offset);

	ft_putlstnbr(piece, 8);
	ft_putchar('\n');
	y = piece[m++];
	x = piece[m++];
	ft_putchar('\n');

	while (j < mapsize)
	{
		i = 0;
		while ((*map)[j][i] != '\0')
		{
			ft_putstr("ia");
			if (j == y && i == x)
			{
				ft_putstr("one");
				//(*map)[i][j] = 'A' + numeropiece; // On marque le caractere dieze dans la map
				(*map)[j][i] = '#'; // On marque le caractere dieze dans la map
				y = piece[m++];
				x = piece[m++];
				ft_putnbr(m);
				ft_putnbr(y);
				ft_putnbr(x);
				//m++; //pour sauter la virgule
			}
			i++;
		}
		j++;
	}
	return (*map);
}

static char		**ft_checkaddblock(int *piece, char ***map, int numeropiece, int mapsize, int **all_tetriminos, int blocknumb)
{
	int i;
	int y;
	int x;
	int m;
	int offset;

	i = 0;
	y = 0;
	x = 0;
	m = 0;
	offset = 0;

	while (i < 8)
	{
		ft_putstr("i : ");
		ft_putnbr(i);
		ft_putchar('\n');
		y = piece[i] + offset;
		x = piece[i + 1] + offset;
		//if (*map[y][x] != '#' && *map[y][x] != '\0')
		if (y >= mapsize || x >= mapsize)
		{
			ft_putstr("recreate new map");
			while (m < mapsize) // je supprime toute ma carte precedente
				free((*map)[m++]);
			free(*map);
			m = 0;
			offset = 0;
			mapsize++; //J'incremente la taille de ma map
			*map = ft_createmap(mapsize);
			resolvesquare(all_tetriminos, blocknumb, mapsize);
			return (NULL);
		}
		if ((*map)[y][x] == '.')
		{
			ft_putnbr(mapsize);
			ft_putnbr(y);
			ft_putnbr(x);
			ft_putnbr(i);
			i = i + 2;// la piece est la j'incremente de 2
			ft_putstr("+\n");
		}
		if ((i == 8) && ((*map)[y][x] == '.')) // Toutes les pieces du tetriminos ont bien des cases vides, j'insere donc la piece
		{
			//inserer piece
			ft_putstr("piece insert");
			ft_putnbr(numeropiece);
			ft_putchar('\n');
			*map = ft_addblock(piece, map, mapsize, offset);
			ft_showmap(*map, mapsize);
			break ;
		}
		if ((*map)[y][x] == '#')
		{
			ft_putstr("offset\n");
			offset++;
		}
	}
	return (*map);
}

int		resolvesquare(int **all_tetriminos, int blocknumb, int mapsize)
{
	int n;
	char **map;

	ft_putstr("resolvesquare\n");
	n = 0;
	mapsize++;
	map = ft_createmap(mapsize);
	ft_showmap(map, mapsize);

	while (n < blocknumb)
	{
		ft_checkaddblock(all_tetriminos[n], &map, n, mapsize, all_tetriminos, blocknumb);
		n++;
	}
		/*
		if (ft_checkaddblock(filecontent[n], &map, n, mapsize, offset) != NULL)
		{ //La piece est bien passé,
			// La piece rentre, on passe donc à la suivante
			n++;
			ft_putstr("piece suivante");
		}
		else
		{
			offset = 0;
			mapsize++;
			ft_putstr("mapsize:");
			ft_putnbr(mapsize);
			ft_putchar('\n');
			free(map);
			map = ft_createmap(mapsize);
			resolvesquare(filecontent, blocknumb, mapsize);
			return (0);
		}
		*/

			// Ou si au bout de la map, Agrandir la taille de la map
			// On re-resous le plus petit carré mais en aggrandissant la map

	// Si toutes les pieces tiennent bien dans la map actuelle, 
	// la créer et l'afficher:
	ft_showmap(map, mapsize);

	//if () // not succeed
	//	ft_putstr("error not resolvesquare");
	return (0);

	//return (map, alphabet, piece);
}

