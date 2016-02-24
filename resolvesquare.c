/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/16 18:43:11 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_createmap(int mapsize)
{
	int x;
	char **map;

	map = (char **)malloc(mapsize * sizeof(char *));
	while (x < mapsize)
	{
		map[x] = (char *)malloc(mapsize * sizeof(char));
		x++;
	}
	return(map);
}

int		ft_checkmap(int x, int y, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (map[j])
	{
		while (map[j][i] != '\0')
		{
			if ((i == x && j == y) && ((char **)map)[j][i] == '#')
				return (1);
			else
				return (0);
			i++;
		}
		j++;
	}
	return (0);
}

int		ft_showmap(char **map)
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



char	**ft_addblock(char *piece, char ***map, int numeropiece)
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
	while (map[j])
	{
		while (map[j][i] != '\0')
		{
			if (j == y && i == x)
			{
				((char **)map)[i][j] = 'A' + numeropiece; // On marque le caractere dize dans la map
				y = piece[m++];
				x = piece[m++];
				m++; //pour sauter la virgule
			}
			i++;
		}
		j++;
	}
	return ((char **)**map);
}

int		ft_checkaddblock(char *curblock, char ***map, int numeropiece, int mapsize, int offset)
{
	int i;
	int y;
	int x;
	int m;
	char *piece;

	i = 0;
	y = 0;
	x = 0;
	m = 0;

	piece = malloc(12);// Malloc pour les 4 diezes (xy,xy,xy,xy,)
	while (curblock[i] != '\0')
	{
		if (curblock[i] == '#')
		{
			// On recupere sa position en x et y (on la deduit)
			y = (curblock[i] / 5); //Soit 1 ligne (et pas ligne 0)
			x = (curblock[i] % 5); //Soit 2 (soit 3 pieces) pour une piece situé en case 8 

			y = y + (offset / 5);
			x = x + (offset % 5);

			 // On verifie que sa position x y n'est pas en dehors de la map, sinon on dit que la map est trop petite.
			if (x  > mapsize || y > mapsize)
				return (1);

			// Si la map est assez grande,
			// on test si sa place est déjà occuppé dans la map
			if (ft_checkmap(x, y, (char **)**map) == 1)				
				return (0);
			else // Sinon je la stocke dans un tableau pour l'inserer +tard
			{
				piece[m++] = y;
				piece[m++] = ',';
				piece[m++] = x;
				piece[m++] = ',';
			}
		}
		i++;
	}
	// On ajoute réellement la piece dans la map.
	map = (char ***)ft_addblock(piece, (char ***)**map, numeropiece);
	return(***map); // Si toutes les pieces rentrent bien dans la map, j'insere la piece, et je sors
}

int		resolvesquare(char **filecontent, int blocknumb, int mapsize)
{
	int n;
	char ***map;
	int offset;

	ft_putstr("resolvesquare");
	n = 0;
	offset = 0;
	mapsize++;
	map = (char ***)ft_createmap(mapsize);

	while (n < blocknumb)
	{
		if (ft_checkaddblock(filecontent[n], (char ***)**map, n, mapsize, offset) == 0)
		{
			// la piece ne rentre pas, on augmente l'offset
			offset++;
		}
		else if (ft_checkaddblock(filecontent[n], (char ***)**map, n, mapsize, offset) == 1)
		{
			offset = 0;
			mapsize++;
			free(map);
			map = (char ***)ft_createmap(mapsize);
			resolvesquare(filecontent, blocknumb, mapsize);
			return (0);
		}
		else { //La piece est bien passé,
			// La piece rentre, on passe donc à la suivante
			n++;
		}
	}


			// Ou si au bout de la map, Agrandir la taille de la map
			// On re-resous le plus petit carré mais en aggrandissant la map
	}

	// Si toutes les pieces tiennent bien dans la map actuelle, 
	// la créer et l'afficher:
	ft_showmap(map);

	//if () // not succeed
	//	ft_putstr("error not resolvesquare");
	return (0);

	//return (map, alphabet, piece);
}

