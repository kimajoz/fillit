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

	j = 0;
	m = 0;
	piece = ft_addoffset_to_piece(piece, offsetY, offsetX); // Si il y a un offset mettre a jour toutes les coordonnees
	y = piece[m++];
	x = piece[m++];
	while (j < mapsize)
	{
		i = 0;
		while (i < mapsize)
		{
			if (j == y && i == x && m <= 8) // J'affiche uniquement pour mes 8 coordonnees
			{
				(*map)[j][i] = 'A' + numeropiece; // On marque le caractere dieze dans la map
				y = piece[m++];
				x = piece[m++];
			}
			i++;
		}
		j++;
	}
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

int		resolvesquare( int ***all_tetriminos, int nombrepieces, char **map, int piece, int mapsize)
{
	int x;
	int y;

	y = 0;
	while (y < mapsize) // I check the position in map
	{
		x = 0;
		while (x < mapsize)
		{
			if (ft_checkaddblock((*all_tetriminos)[piece], &map, mapsize, y, x) == 0) //la piece ne rentre pas
				x++;
			else
			{
				ft_addblock((*all_tetriminos)[piece], piece, &map, mapsize, y, x);
				if (piece == (nombrepieces - 1))
					return 1;
				if (resolvesquare(all_tetriminos, nombrepieces, map, piece + 1, mapsize) == 0)
					ft_removeblock(piece, &map, mapsize);
				else
					return 1;
				x++;
			}
		}
		y++;
	}
	return (0);
} 
