/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:48:10 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/09 11:27:48 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_number_of_hash(int *car, int *comptdieze, int *comptpoint,
		int *ligne)
{
	if (*ligne != 4 || *comptdieze != 4 || *comptpoint != 12)
		return (1);
	*car = -1;
	*ligne = 0;
	*comptdieze = 0;
	*comptpoint = 0;
	return (0);
}

static int	add_to_compter(char my_block_i, int *comptdieze, int *comptpoint,
		int *ligne)
{
	if (my_block_i == '#')
		(*comptdieze)++;
	if (my_block_i == '.')
		(*comptpoint)++;
	if (my_block_i == '\n')
		(*ligne)++;
	return (0);
}

int			filter_file(char *my_block, int i, int car, int ligne)
{
	int		comptdieze;
	int		comptpoint;

	comptdieze = 0;
	comptpoint = 0;
	while (my_block[i] != '\0')
	{
		if (my_block[i] != '\n' && my_block[i] != '.' && my_block[i] != '#')
			return (1);
		if (my_block[i + 1] == '\0' ||
				(my_block[i] == '\n' && my_block[i - 1] == '\n'))
		{
			if (check_number_of_hash(&car, &comptdieze, &comptpoint,
						&ligne) == 1)
				return (1);
		}
		if (car < 19)
		{
			car++;
			add_to_compter(my_block[i], &comptdieze, &comptpoint, &ligne);
		}
		i++;
	}
	return (0);
}
