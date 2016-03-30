/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/03/30 14:08:42 by pbillett         ###   ########.fr       */
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

static char		**ft_addblock(int *piece, int numeropiece, char ***map, int mapsize, int offsetY, int offsetX)
{
	int i;
	int j;
	int x;
	int y;
	int m;

	i = 0;
	j = 0;
	m = 0;
	
	ft_putlstnbr(piece, 8);
	ft_putchar('\n');

	if ((offsetX != 0) || (offsetY != 0)) // Si il y a un offset mettre a jour toutes les coordonnees
	{
		ft_putstr("testpapa");
		while (i < 8)
		{
			piece[i] = piece[i] + offsetY; // On ajoute loffset en Y
			piece[i + 1] = piece[i + 1] + offsetX; // Sinon en X
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
				(*map)[j][i] = 'A' + numeropiece; // On marque le caractere dieze dans la map
				//(*map)[j][i] = '#'; // On marque le caractere dieze dans la map
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

	ft_putstr("offsetY : ");
	ft_putnbr(offsetY);
	ft_putchar('\n');
	ft_putstr("offsetX : ");
	ft_putnbr(offsetX);
	ft_putchar('\n');
	
	ft_putstr("je teste piece numero : ");
	ft_putnbr(numeropiece);
	ft_putchar('\n');
	
	ft_putstr("Mapsize : ");
	ft_putnbr(mapsize);
	ft_putchar('\n');

	// SI CA RENTRE ON RETOURNE LA NOUVELLE MAP AVEC LA PIECE.
	// SINON ON RETOURNE NULL ! (ON FAIT L'INCREMENTE DE L'OFFSET A L'EXTERIEUR.)

	// Verification que l'on est pas en dehors de la map avant le demarrage du test de placage de la piece dans une map trop petite
	while (i < 8)
		{
			//ft_putnbr(i);
			if (((piece[i] + offsetY) >= mapsize) || ((piece[i + 1] + offsetX) >= mapsize))
			{
				return(NULL);
			}
			i = i + 2;
		}
	ft_putlstnbr(piece, 8);
	ft_putchar('\n');


	if ((*map)[(piece[0] + offsetY)][(piece[1] + offsetX)] == '#' ||
	(*map)[(piece[2] + offsetY)][(piece[3] + offsetX)] == '#' ||
	(*map)[(piece[4] + offsetY)][(piece[5] + offsetX)] == '#' ||
	(*map)[(piece[6] + offsetY)][(piece[7] + offsetX)] == '#')
	{
		return (NULL);
	}

	if ((*map)[(piece[0] + offsetY)][(piece[1] + offsetX)] == '.' &&
	(*map)[(piece[2] + offsetY)][(piece[3] + offsetX)] == '.' &&
	(*map)[(piece[4] + offsetY)][(piece[5] + offsetX)] == '.' &&
	(*map)[(piece[6] + offsetY)][(piece[7] + offsetX)] == '.')
	{
		//inserer la piece
		ft_putstr("piece insert n");
		ft_putnbr(numeropiece);
		ft_putchar('\n');
		*map = ft_addblock(piece, numeropiece, map, mapsize, offsetY, offsetX);
		ft_putstr("MAP : INSERT PIECE\n");
		ft_showmap(*map, mapsize);
		return (*map);
	}
	return (NULL);
}

int		checkpositioninmap( int ***all_tetriminos, int nombrepieces, int mapsize, char **map, int numpiece_actuelle)
{
	int y;
	int x;
	int m;
	int numprevious_piece;
	
	y = 0;
	x = 0;
	m = 0;
	while (numpiece_actuelle < nombrepieces)
	{
		numprevious_piece = numpiece_actuelle;
		while (y < mapsize)
		{
			x = 0;
			while (x < mapsize)
			{
				ft_putstr("x:");
				ft_putnbr(x);
				ft_putchar('\n');
				ft_putstr("y:");
				ft_putnbr(y);
				ft_putchar('\n');

				if (ft_checkaddblock((*all_tetriminos)[numpiece_actuelle], &map, numpiece_actuelle, mapsize, y, x) == NULL)
				{	
					x++;
					//ELSE
					// LA PIECE NE RENTRE PAS !
					// ON INCREMENTE DONC SA POSITION DANS LA MAP ACTUELLE JUSQU'A SA FIN ! (pour essayer de trouver une autre place ;))
				}
				else
				{
					ft_putstr("Piece suivante !\n");
					numpiece_actuelle++;
					// Je reset la position de l'offset pour redemarrer au debut de la carte:
					y = 0;
					x = 0;
					if (numpiece_actuelle == nombrepieces)
					{
						ft_putstr("fini d'inserer toutes les pieces.");
						ft_showmap(map, mapsize);
						return (1);
					}
				}
			}
			y++;
		}
		
		if (numprevious_piece == numpiece_actuelle) // Si la piece n'a pas été inséré, alors:
		{
			ft_putstr("En dehors de la carte ! je recree une map plus grande.\n");
			// recreer la map
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
			numpiece_actuelle = 0;
			checkpositioninmap(all_tetriminos, nombrepieces, mapsize, map, numpiece_actuelle);
			return (0);
		}
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
	checkpositioninmap(&all_tetriminos, nombrepieces, mapsize, map, n);
	/*
	while (n < nombrepieces)
	{
		if (checkpositioninmap(&all_tetriminos, nombrepieces, mapsize, map, n) == 0)
		{
									//checkpositioninmap(&all_tetriminos, nombrepieces, mapsize, map, n);
		}
		else if (checkpositioninmap(&all_tetriminos, nombrepieces, mapsize, map, n) == 1)
		{
			//ft_putstr("test46");
			//n++;
			//checkpositioninmap(&all_tetriminos, nombrepieces, mapsize, map, n);
		}
	}
	{
		ft_putstr("fini d'inserer toutes les pieces.");
		ft_showmap(map, mapsize);
		return (0);
	}
	*/
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

