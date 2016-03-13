/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:22:34 by pbillett          #+#    #+#             */
/*   Updated: 2016/03/02 13:55:21 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		*create_tetriminos(char *curblock, int numeropiece)
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
	if (piece == NULL)
		return (NULL);
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
	ft_putstr(" piece ");
	ft_putnbr(numeropiece);
	ft_putstr(": ");
	ft_putlstnbr(piece, 8);
	ft_putstr("\n");
	return (piece); // Si toutes les pieces rentrent bien dans la map, j'insere la piece, et je sors
}

static int			**remove_free_line(int **pieces, int numberofpiece)
{
	int n;

	n = 0;
	while(n < numberofpiece)
	{
		while ((pieces[n][0] > 0) && (pieces[n][2] > 0) && (pieces[n][4] > 0) && (pieces[n][6] > 0))
		{
			pieces[n][0]--;
			pieces[n][2]--;
			pieces[n][4]--;
			pieces[n][6]--;
		}
		while ((pieces[n][1] > 0) && (pieces[n][3] > 0) && (pieces[n][5] > 0) && (pieces[n][7] > 0))
		{
			pieces[n][1]--;
			pieces[n][3]--;
			pieces[n][5]--;
			pieces[n][7]--;
		}
		n++;
	}
	return(pieces);
}

static void		show_tetriminos(int **pieces, int numberofpiece)
{
	int i;

	i = 0;
	ft_putstr("The list of my tetriminos blocks : (with y,x,y,x,y,x,y,x coordonnate) for each # carateres\n");
	while (i < numberofpiece)
	{
		// On ajoute réellement la piece dans la map.
		ft_putstr(" piece ");
		ft_putnbr(i);
		ft_putstr(": ");
		ft_putlstnbr(pieces[i], 8);
		ft_putstr("\n");
		i++;
	}
}


int			**create_all_tetriminos(char **filecontent, int numberofpiece)
{
	int n;
	int *piece;
	int **pieces;

	piece = malloc(8 * sizeof(int));
	if (piece == NULL)
		return (0);
	pieces = malloc(numberofpiece * sizeof(piece));
	if (pieces == NULL)
		return (0);
	ft_putstr("create_all_tetriminos\n");
	n = 0;
	ft_putstr("The list of my tetriminos blocks : (with y,x,y,x,y,x,y,x coordonnate) for each # carateres\n");
	while (n < numberofpiece)
	{
		pieces[n] = create_tetriminos(filecontent[n], n);
		n++;
	}
	remove_free_line(pieces, numberofpiece);
	show_tetriminos(pieces, numberofpiece);
	return (pieces);
}
