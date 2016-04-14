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

int              ft_showmap(char **map, int mapsize)
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

char     **ft_createmap(int mapsize)
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
		//ft_putstr("Je montre nouvelle map fraiche\n");
		//ft_showmap(map, mapsize);
        return(map);
}

static int		*ft_addoffset_to_piece(int *piece, int offsetY, int offsetX)
{
	int i;

	i = 0;
	ft_putstr("Add offset to piece \n");
	while (i < 8)
	{
		piece[i] = piece[i] + offsetY; // On ajoute loffset en Y
		piece[i + 1] = piece[i + 1] + offsetX; // Sinon en X
		i = i + 2;
	}
	return (piece);
}

static char		**ft_removeblock(int pieceasupprimer, char ***map, int mapsize)
{
	int i;
	int j;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (j < mapsize)
	{
		i = 0;
		while (i < mapsize)
		{
			if ((*map)[j][i] == ('A' + pieceasupprimer))
			{
				(*map)[j][i] = '.';
			}
			i++;
		}
		j++;
	}
	ft_putstr("Map with block deleted : \n");
	ft_showmap(*map, mapsize);
	return (*map);
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
		ft_addoffset_to_piece(piece, offsetY, offsetX);
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
		while (i < mapsize)
		{
			if (j == y && i == x)
			{
				if (m <= 8) // J'affiche uniquement pour mes 8 coordonnees
				{
					(*map)[j][i] = 'A' + numeropiece; // On marque le caractere dieze dans la map
					ft_putnbr(y);
					ft_putnbr(x);
					y = piece[m++];
					x = piece[m++];
					ft_putchar('\n');
				}
			}
			i++;
		}
		j++;
	}
	ft_putstr("end_add\n");
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

int		resolvesquare( int ***all_tetriminos, int nombrepieces, int mapsize, char **map, int numpiece_actuelle, int y, int x)
{
	int m;
	int numprevious_piece;
	
	y = 0;
	x = 0;
	m = 0;
	while (numpiece_actuelle < nombrepieces) // I go throught all my blocks
	{
		numprevious_piece = numpiece_actuelle;
		while (y < mapsize) // I check the position in map
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
					ft_putstr("LA PIECE NE RENTRE PAS !\n");
					ft_putnbr(numprevious_piece);
					ft_putnbr(numpiece_actuelle);
					// ON INCREMENTE DONC SA POSITION DANS LA MAP ACTUELLE JUSQU'A SA FIN ! (pour essayer de trouver une autre place ;))

					if (numprevious_piece == numpiece_actuelle && numpiece_actuelle != 0) // Si ce n'est pas la piece actuelle et que j'ai au moins insere une piece :)
					{
						ft_putstr("--> BACKTRACKING !\n");
						// On reviens a la piece precedente (we skip the whole sub-tree !)
						numpiece_actuelle--;
						// On supprime donc la piece anterieur:
						ft_removeblock(numpiece_actuelle, &map, mapsize);
						// Et on rappelle la fonction avec la piece precedente mais a la position suivante
						resolvesquare(all_tetriminos, nombrepieces, mapsize, map, numpiece_actuelle, previousY, (previousX + 1));
						//y = previousY;
						//x = previousX + 1;
					}
				}
				else
				{
					// J'enregistre ma position xy pour l'insere de ma piece courant (pour la Backtracking)
					previousY = y;
					previousX = x;
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
					// Je rappelle ma fonction en recommencant a zero (au debut de ma map)
					resolvesquare(all_tetriminos, nombrepieces, mapsize, map, numpiece_actuelle, 0, 0);
					return (0);
				}
			}
			y++;
		}

		//if (numprevious_piece != numpiece_actuelle) // Si la piece a été inséré, alors:
		//{
			ft_putstr("----------------------------------------------------");
			ft_putstr("numpiece_actuelle++");
			numpiece_actuelle++;
			ft_putnbr(numpiece_actuelle);
			ft_putchar('\n');
			x = 0;
			y = 0;
			//resolvesquare(all_tetriminos, nombrepieces, mapsize, map, numpiece_actuelle, 0, 0);
		//}

		if (numpiece_actuelle == nombrepieces && mapsize < 3) // Si on est arrivee a la fin de la map et que la piece n'a pas été inséré, alors:
		{
			//ft_putstr("Aucune piece n'est rentre dans le map ! je recree une map plus grande.\n");
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
			resolvesquare(all_tetriminos, nombrepieces, mapsize, map, numpiece_actuelle, 0, 0);
			return (0);
		}
	}
	return (0);
}

char			*select_size_of_map(int **pieces)
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


int				back(int p, int id_piece, char *map, int **pieces)
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
