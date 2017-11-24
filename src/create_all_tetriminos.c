/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:22:34 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/10 14:33:19 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		*create_tetriminos(char *curblock)
{
	int			i;
	int			y;
	int			x;
	int			m;
	int			*piece;

	i = 0;
	y = 0;
	x = 0;
	m = 0;
	piece = malloc(8 * sizeof(int));
	if (piece == NULL)
		return (NULL);
	while (curblock[i] != '\0')
	{
		if (curblock[i] == '#')
		{
			y = (i / 5);
			x = (i % 5);
			piece[m++] = y;
			piece[m++] = x;
		}
		i++;
	}
	return (piece);
}

static int		**remove_free_line(int **pieces, int numberofpiece)
{
	int			n;

	n = 0;
	while (n < numberofpiece)
	{
		while ((pieces[n][0] > 0) && (pieces[n][2] > 0) &&
				(pieces[n][4] > 0) && (pieces[n][6] > 0))
		{
			pieces[n][0]--;
			pieces[n][2]--;
			pieces[n][4]--;
			pieces[n][6]--;
		}
		while ((pieces[n][1] > 0) && (pieces[n][3] > 0) &&
				(pieces[n][5] > 0) && (pieces[n][7] > 0))
		{
			pieces[n][1]--;
			pieces[n][3]--;
			pieces[n][5]--;
			pieces[n][7]--;
		}
		n++;
	}
	return (pieces);
}

int				**create_all_tetriminos(char **filecontent, int numberofpiece)
{
	int			n;
	int			*piece;
	int			**pieces;

	piece = malloc(8 * sizeof(int));
	if (piece == NULL)
		return (0);
	pieces = malloc(numberofpiece * sizeof(piece));
	if (pieces == NULL)
		return (0);
	n = 0;
	while (n < numberofpiece)
	{
		pieces[n] = create_tetriminos(filecontent[n]);
		n++;
	}
	remove_free_line(pieces, numberofpiece);
	return (pieces);
}
