/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/04/14 20:01:41 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*ft_addoffset_to_piece(int *piece, int offsetY, int offsetX)
{
	int i;
	int *newpiece;

	i = 0;
	newpiece = malloc(8 * sizeof(int));// Malloc pour les 4 diezes (xy,xy,xy,xy,)
	if (newpiece == NULL)
		return (NULL);

	while (i < 8)
	{
		newpiece[i] = piece[i] + offsetY; // On ajoute loffset en Y
		newpiece[i + 1] = piece[i + 1] + offsetX; // Sinon en X
		i = i + 2;
	}
	return (newpiece);
}

static char		**ft_removeblock(int pieceasupprimer, char ***map, int mapsize)
{
	int i;
	int j;

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

static char		**ft_addblock(int *piece, int numeropiece, char ***map, int mapsize, int offsetY, int offsetX)
{
	int i;
	int j;
	int x;
	int y;
	int m;
	int *newpiece;

	ft_putlstnbr(piece, 8);
	newpiece = malloc(8 * sizeof(int));// Malloc pour les 4 diezes (xy,xy,xy,xy,)
	if (newpiece == NULL)
		return (NULL);
	i = 0;
	j = 0;
	m = 0;
	// Si il y a un offset mettre a jour toutes les coordonnees
	newpiece = ft_addoffset_to_piece(piece, offsetY, offsetX);
	y = newpiece[m++];
	x = newpiece[m++];
	while (j < mapsize)
	{
		i = 0;
		while (i < mapsize)
		{
			if (j == y && i == x)
			{
				if (m <= 8) // J'affiche uniquement pour mes 8 coordonnees
				{
					(*map)[j][i] = 'A' + numeropiece; // On marque le caractere dieze dans la map
					y = newpiece[m++];
					x = newpiece[m++];
				}
			}
			i++;
		}
		j++;
	}
	ft_showmap(*map, mapsize);
	return (*map);
}

static int		ft_checkaddblock(int *piece, char ***map, int mapsize, int offsetY, int offsetX)
{
	int i;

	i = 0;
	// SI CA RENTRE ON RETOURNE LA NOUVELLE MAP AVEC LA PIECE. SINON ON RETOURNE NULL ! (ET ON FAIT L'INCREMENTE DE L'OFFSET A L'EXTERIEUR.)
	// Verification que l'on est pas en dehors de la map avant le demarrage du test de placage de la piece dans une map trop petite
	while (i < 8)
		{
			if (((piece[i] + offsetY) >= mapsize) || ((piece[i + 1] + offsetX) >= mapsize))
				return(0);
			i = i + 2;
		}
	if ((*map)[(piece[0] + offsetY)][(piece[1] + offsetX)] == '#' ||
	(*map)[(piece[2] + offsetY)][(piece[3] + offsetX)] == '#' ||
	(*map)[(piece[4] + offsetY)][(piece[5] + offsetX)] == '#' ||
	(*map)[(piece[6] + offsetY)][(piece[7] + offsetX)] == '#')
		return (0);
	if ((*map)[(piece[0] + offsetY)][(piece[1] + offsetX)] == '.' &&
	(*map)[(piece[2] + offsetY)][(piece[3] + offsetX)] == '.' &&
	(*map)[(piece[4] + offsetY)][(piece[5] + offsetX)] == '.' &&
	(*map)[(piece[6] + offsetY)][(piece[7] + offsetX)] == '.')
	{
		return (1);
	}
	return (0);
}

static char		**increase_mapsize(char **map, int mapsize)
{
	int m;

	m = 0;
	ft_putstr("function increase_mapsize\n");
	while (m < (mapsize - 1)) // je supprime toute ma carte precedente
	{
		free(map[m]);
		m++;
	}
	free(map);

	ft_putstr("function increase_mapsize free ok\n");
	m = 0;
	mapsize++;
	ft_putnbr(mapsize);
	map = ft_createmap(mapsize);
	ft_showmap(map, mapsize);
	ft_putstr("function increase_mapsize end\n");
	return (map);
}

int		resolvesquare( int ***all_tetriminos, int nombrepieces, char **map, int piece, int mapsize)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < mapsize) // I check the position in map
	{
		x = 0;
		while (x < mapsize)
		{
			if (ft_checkaddblock((*all_tetriminos)[piece], &map, mapsize, y, x) == 0) //la piece ne rentre pas
			{
				ft_putstr("t");
				x++;
			}
			else
			{
				ft_putstr("j'insere piece ");
				ft_putnbr(piece);
				ft_putchar('\n');
				ft_addblock((*all_tetriminos)[piece], piece, &map, mapsize, y, x);
				if (piece == (nombrepieces - 1))
				{
					ft_putstr("fin resolve");
					ft_showmap(map, mapsize);
					return 1;
					ft_putchar('a');
					//break ;
				}
				if (resolvesquare(all_tetriminos, nombrepieces, map, piece + 1, mapsize) == 0)
				{
					ft_putstr("j'enleve piece ");
					ft_putnbr(piece);
					ft_putchar('\n');
					ft_removeblock(piece, &map, mapsize);
					//x++;
				}
				else
					return 1;
					//return (resolvesquare(all_tetriminos, nombrepieces, map, piece + 1, mapsize));
				x++;
			}
		}
		y++;
	}
	ft_putstr("popo\n");
	return (0);
}

int             resolve_smallest_square(int **all_tetriminos, int nombrepieces, int mapsize)
{
	int n;
	char **map;

	n = 0;
    map = ft_createmap(mapsize);
    ft_showmap(map, mapsize);

	//resolvesquare(&all_tetriminos, nombrepieces, map, n, mapsize);
	while (resolvesquare(&all_tetriminos, nombrepieces, map, n, mapsize) != 1 && mapsize < 6)
	{
			ft_putstr("tr :\n");
			//ft_putnbr(mapsize);
			//ft_putchar('\n');
			map = increase_mapsize(map, mapsize++);
	}
	ft_putstr("fin tout ! \n");
	ft_showmap(map, mapsize);
	return (0);
}

/*
static char			*select_size_of_map(int **pieces)
{
	char		*map;
	int			i;

	i = 2;
	map = ft_memalloc(i * i + 1);
	while (1)
	{
		if (back(0, 0, map, pieces) == 1)
			break ;
		i++;
		map = ft_memalloc(i * i);
	}
	return (map);
}

static int				back(int p, int id_piece, char *map, int **pieces)
{
	if (id_piece == max_piece)
		return (1);
	while (jepeuxpasposermappiece(map, p, pieces[id_piece]))
	{
		p++;
		if (map[p] == '\0')
			return (0);
	}
	poserpiece(id_piece, pieces, map, p);
	if (back(0, id_piece + 1, map, pieces))
		effacer_la_piece_actuelle;
	return (back(p + 1, id_piece, map, pieces));
}
*/
