/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/03/05 19:29:23 by pbillett         ###   ########.fr       */
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
	ft_putstr("I show the map :");
	ft_putnbr(mapsize);
	ft_putchar('\n');
	while (j < mapsize)
	{
		//ft_putstr("test");
		while (i < mapsize) // Attention ici il faut mettre un \0 lors de l'allocation si on avait voulu s'arreter a la fin de la chaine de caracteres sous cette condition.
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

static char		**ft_addblock(int *piece, char ***map, int mapsize, int offsetY, int offsetX)
{
	int i;
	int j;
	int x;
	int y;
	int m;

	i = 0;
	j = 0;
	m = 0;

	if ((offsetX != 0) || (offsetY != 0)) // Si il y a un offset mettre a jour toutes les coordonnees
	{
		while (piece[i] != '\0')
		{
			piece[i] = piece[i] + offsetY;
			piece[i + 1] = piece[i + 1] + offsetX;
			i = i + 2;
		}
		i = 0;
	}
	ft_putnbr(offsetY);
	ft_putnbr(offsetX);

	ft_putchar('\n');
	y = piece[m++];
	x = piece[m++];
	ft_putstr("mapsize");
	ft_putnbr(mapsize);
	ft_putchar('\n');
	ft_putlstnbr(piece, 8);
	ft_putchar('\n');

	while (j < mapsize)
	{
		i = 0;
		while ((*map)[j][i] != '\0')
		{
			//ft_putstr("ia");
			if (j == y && i == x)
			{
				//ft_putstr("one");
				//(*map)[i][j] = 'A' + numeropiece; // On marque le caractere dieze dans la map
				(*map)[j][i] = '#'; // On marque le caractere dieze dans la map
				ft_putnbr(y);
				ft_putnbr(x);
				//ft_putnbr(m);
				y = piece[m++];
				x = piece[m++];
				//m++; //pour sauter la virgule
			}
			i++;
		}
		j++;
	}
	return (*map);
}

static char		**ft_checkaddblock(int *piece, char ***map, int numeropiece, int mapsize, int offsetY, int offsetX)
{
	int i;

	i = 0;
	ft_putstr("ft_checkaddblock\n");
	ft_putnbr(offsetY);
	ft_putnbr(offsetX);
	ft_putstr("je teste piece numero : ");
	ft_putnbr(numeropiece);
	ft_putchar('\n');

	// Verification aue l'on est pas en dehors de la map avant le demarrage du test de placage de la piece dans une map trop petite
	while (i < 8)
		{
			//ft_putnbr(i);
			if (((piece[i] + offsetY) >= mapsize) || ((piece[i + 1] + offsetX) >= mapsize))
			{
				ft_putstr("ft_checkaddblockZZZ");
				return (NULL);
			}
			i++;
		}

	while ((*map)[(piece[0] + offsetY)][(piece[1] + offsetX)] != '.' &&
	(*map)[(piece[2] + offsetY)][(piece[3] + offsetX)] != '.' &&
	(*map)[(piece[4] + offsetY)][(piece[5] + offsetX)] != '.' &&
	(*map)[(piece[6] + offsetY)][(piece[7] + offsetX)] != '.')
	{
		while (i < 8)
		{
			//ft_putnbr(i);
			if (((piece[i] + offsetY) >= mapsize) || ((piece[i + 1] + offsetX) >= mapsize))
			{
				ft_putstr("ft_checkaddblockZZZ");
				return (NULL);
			}
			i++;
		}
			//ft_putstr("ft_checkaddblockA");
		if ((*map)[(piece[0] + offsetY)][(piece[1] + offsetX)] == '#' ||
		(*map)[(piece[2] + offsetY)][(piece[3] + offsetX)] == '#' ||
		(*map)[(piece[4] + offsetY)][(piece[5] + offsetX)] == '#' ||
		(*map)[(piece[6] + offsetY)][(piece[7] + offsetX)] == '#')
		{
			ft_putstr("offset\n");
			if (offsetX > mapsize)
			{
				offsetY++;
				offsetX = 0;
			}
			else
				offsetX++;
		}
	}
	if ((*map)[(piece[0] + offsetY)][(piece[1] + offsetX)] == '.' &&
	(*map)[(piece[2] + offsetY)][(piece[3] + offsetX)] == '.' &&
	(*map)[(piece[4] + offsetY)][(piece[5] + offsetX)] == '.' &&
	(*map)[(piece[6] + offsetY)][(piece[7] + offsetX)] == '.')
	{
		//inserer la piece
		ft_putstr("piece insert");
		ft_putnbr(numeropiece);
		ft_putchar('\n');
		*map = ft_addblock(piece, map, mapsize, offsetY, offsetX);
		ft_putstr("MAP : INSERT PIECE");
		ft_showmap(*map, mapsize);
		return (*map);
	}
	return (*map);
}

int		checkpositioninmap( int ***all_tetriminos, int nombrepieces, int mapsize, char **map, int numpiece_actuelle)
{
	int y;
	int x;
	int m;
	
	y = 0;
	x = 0;
	m = 0;
	while (numpiece_actuelle < nombrepieces)
	{
		while (y < mapsize)
		{
			x = 0;
			while (map[y][x] != '0')
			{
				if (ft_checkaddblock((*all_tetriminos)[numpiece_actuelle], &map, numpiece_actuelle, mapsize, y, x) == NULL)
				{
					// recreer la map
					ft_putstr("recreate new map");
					while (m < mapsize) // je supprime toute ma carte precedente
					{
						free(map[m]);
						m++;
					}
						free(map);
					m = 0;
					mapsize++; //J'incremente la taille de ma map
					ft_putnbr(mapsize);
					map = ft_createmap(mapsize);
					resolvesquare(*all_tetriminos, nombrepieces, mapsize);
					return (0);
				}
				else
				{
					//ft_putstr("-----------------------------------------------------------\n");
					//map = ft_checkaddblock((*all_tetriminos)[numpiece_actuelle], &map, numpiece_actuelle, mapsize, y, x);
					//ft_showmap(map, mapsize);
					numpiece_actuelle++;

					checkpositioninmap(all_tetriminos, nombrepieces, mapsize, map, numpiece_actuelle);
					return(1);
				}
				x++;
			}
			y++;
		}
	}
	if (numpiece_actuelle == nombrepieces)
	{
		ft_putstr("fini d'inserer toutes les pieces.");
		ft_showmap(map, mapsize);
		return (0);
	}
	return (0);
}

int		resolvesquare(int **all_tetriminos, int nombrepieces, int mapsize)
{
	int n;
	char **map;

	n = 0;
	ft_putstr("resolvesquare\n");
	map = ft_createmap(mapsize);
	ft_showmap(map, mapsize);

	while (n < nombrepieces)
	{
		checkpositioninmap(&all_tetriminos, nombrepieces, mapsize, map, n);
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
	//ft_showmap(map, mapsize);

	//if () // not succeed
	//	ft_putstr("error not resolvesquare");
	return (0);

	//return (map, alphabet, piece);
}

