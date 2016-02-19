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

	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if ((i == x && j == y) && ((char **)map)[i][j] == '#')
				return (1);
			else
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_addblock(char *piece, char **map)
{
	int i;
	int j;
	int x;
	int y;
	int m;

	i = 0;
	j = 0;
	m = 0;

	x = piece[m];
	y = piece[m++];
	m++; //pour sauter la virgule
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (i == x && j == y)
			{
				((char **)map)[i][j] = '#'; // On marque le caractere dize dans la map
				x = piece[m++];
				y = piece[m++];
				m++; //pour sauter la virgule
			}
			j++;
		}
		i++;
	}
	return ((char **)**map);
}

int		ft_checkaddblock(char *curblock, char ***map)
{
	int i;
	int x;
	int y;
	int m;
	char *piece;

	i = 0;
	x = 0;
	y = 0;
	m = 0;

	piece = malloc(12);// Malloc pour les 4 diezes (xy,xy,xy,xy,)
	while (curblock[i] != '\0')
	{
		if (curblock[i] == '#')
		{
			// On recupere sa position en x et y (on la deduit)
			x = (curblock[i] % 5); //Soit 2 (soit 3 pieces) pour une piece situé en case 8 
			y = (curblock[i] / 5); //Soit 1 ligne (et pas ligne 0)

			// Puis on test si sa place est déjà occuppé dans la map
			if (ft_checkmap(x, y, (char **)**map) == 1)
				return (0);
			else // Sinon je la stocke dans un tableau pour l'inserer +tard
			{
				piece[m++] = x;
				piece[m++] = ',';
				piece[m++] = y;
				piece[m++] = ',';
			}
		}
		i++;
	}
	// On ajoute réellement la piece dans la map.
	map = (char ***)ft_addblock(piece, (char **)**map);
	return(***map); // Si toutes les pieces rentrent bien dans la map, j'insere la piece, et je sors
}

int		resolvesquare(char **filecontent, int blocknumb, int mapsize)
{
	int n;
	int i;
	char ***map;

	ft_putstr("resolvesquare");
	n = 0;
	i = 0;
	mapsize++;

	map = (char ***)ft_createmap(mapsize);

	while (n < blocknumb)
	{
		/*while (filecontent[n][i] != '\0')
		{
			//ft_putchar(filecontent[n][i]);
			i++;
		}*/
		ft_putnbr(n);
		ft_putstr(filecontent[n]);
		ft_putchar('\n');
		if (ft_checkaddblock(filecontent[n], (char ***)**map) != 0)
		{
			// La piece a été inseré, on passe à celle d'après
			n++;
		}
		else
		{
			// Décaler la piece vers la droite ou sauter une ligne
			
			
			// Ou si au bout de la map, Agrandir la taille de la map
			// On re-resous le plus petit carré mais en aggrandissant la map
			resolvesquare(filecontent, blocknumb, mapsize);
		}
	}

	//if () // not succeed
	//	ft_putstr("error not resolvesquare");
	return (0);

	//return (map, alphabet, piece);
}

