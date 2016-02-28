/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/26 18:03:46 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_createmap(int mapsize)
{
	int x;
	char **map;

	x = 0;
	map = (char **)malloc(mapsize * sizeof(char *));
	while (x < mapsize)
	{
		map[x] = (char *)malloc(mapsize * sizeof(char));
		x++;
	}
	return(map);
}

static int		ft_checkmap(int x, int y, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	//ft_putstr("start check_map");

	while (map[j])
	{
		while (map[j][i] != '\0')
		{
			if ((i == x && j == y) && (map[j][i] == '#'))
				return (1);
			else
				return (0);
			i++;
		}
		j++;
	}
	return (0);
}

static int		ft_showmap(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr("I show the map : \n\n");

	while (map[j])
	{
		while (map[j][i] != '\0')
		{
			ft_putchar(map[j][i]);
			i++;
		}
		j++;
	}
	return (0);
}
/*
static char	**ft_addblock(int *piece, char ***map, int numeropiece)
{
	int i;
	int j;
	int x;
	int y;
	int m;

	i = 0;
	j = 0;
	m = 0;

	y = piece[m];
	x = piece[m++];
	m++; //pour sauter la virgule
	while ((*map)[j])
	{
		while ((*map)[j][i] != '\0')
		{
			if (j == y && i == x)
			{
				(*map)[i][j] = 'A' + numeropiece; // On marque le caractere dize dans la map
				y = piece[m++];
				x = piece[m++];
				m++; //pour sauter la virgule
			}
			i++;
		}
		j++;
	}
	return (*map);
}
*/
static char		**ft_checkaddblock(char *curblock, char ***map, int numeropiece, int mapsize, int offset)
{
	int i;
	int y;
	int x;
	int m;
	int *piece;

	i = 0;
	y = 0;
	x = 0;
	m = 0;

	piece = malloc(8 * sizeof(int));// Malloc pour les 4 diezes (xy,xy,xy,xy,)
	while (!(piece[8]))
	{
		while (curblock[i] != '\0')
		{
			if (curblock[i] == '#')
			{
				if (((ft_checkmap(x, y, *map)) == 1) && (x < mapsize && y < mapsize)) // Tant que ca tient dans la map
				{
					// On recupere sa position en x et y (on la deduit)
					y = ((i + offset) / 5); //Soit 1 ligne (et pas ligne 0)
					//ft_putnbr(y);
					x = ((i + offset) % 5); //Soit 2 (soit 3 pieces) pour une piece situé en case 8 
					//ft_putnbr(x);
					// Sinon je la stocke dans un tableau pour l'inserer +tard
					piece[m++] = y;
					piece[m++] = x;
					ft_putstr("try ok");

					if (!(piece[8]))
					{
						// On ajoute réellement la piece dans la map.
						ft_putnbr(numeropiece);
						ft_putstr(" piece : ");
						ft_putlstnbr(piece, 8);
						ft_putstr("\n");
						//*map = ft_addblock(piece, map, numeropiece);
						return(*map); // Si toutes les pieces rentrent bien dans la map, j'insere la piece, et je sors
					}
				}
				else if (y > mapsize)
				{
					ft_putstr("try ok");
					return (NULL);
				}
				offset++;
			}
			i++;
		}
	}
	return (NULL);
}

static int		*ft_createtetriminos(char *curblock, char ***map, int numeropiece, int mapsize, int offset)
{
	int i;
	int y;
	int x;
	int m;
	int *piece;

	i = 0;
	y = 0;
	x = 0;
	m = 0;

	piece = malloc(8 * sizeof(int));// Malloc pour les 4 diezes (xy,xy,xy,xy,)
	while (curblock[i] != '\0')
	{
		if (curblock[i] == '#')
		{
				// On recupere sa position en x et y (on la deduit)
				y = (i / 5); //Soit 1 ligne (et pas ligne 0)
				//ft_putnbr(y);
				x = (i  % 5); //Soit 2 (soit 3 pieces) pour une piece situé en case 8 
				//ft_putnbr(x);
				// Sinon je la stocke dans un tableau pour l'inserer +tard
				piece[m++] = y;
				piece[m++] = x;
		}
		i++;
	}
	// On ajoute réellement la piece dans la map.
	ft_putnbr(numeropiece);
	ft_putstr(" piece : ");
	ft_putlstnbr(piece, 8);
	ft_putstr("\n");
	*totpiece = ft_addblock(piece, map, numeropiece);
	//return(*map); // Si toutes les pieces rentrent bien dans la map, j'insere la piece, et je sors

}

int		resolvesquare(char **filecontent, int blocknumb, int mapsize)
{
	int n;
	char **map;
	int offset;

	ft_putstr("resolvesquare\n");
	n = 0;
	offset = 0;
	//mapsize++;
	//map = ft_createmap(mapsize);

	while (n < blocknumb)
	{
		ft_putstr("The list of my tetriminos blocks : (with y,x,y,x,y,x,y,x coordonnate) for each # carateres");
		ft_createtetriminos(filecontent[n], &map, n, mapsize, offset);
		n++;
		
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
	}

			// Ou si au bout de la map, Agrandir la taille de la map
			// On re-resous le plus petit carré mais en aggrandissant la map

	// Si toutes les pieces tiennent bien dans la map actuelle, 
	// la créer et l'afficher:
	ft_showmap(map);

	//if () // not succeed
	//	ft_putstr("error not resolvesquare");
	return (0);

	//return (map, alphabet, piece);
}

