/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:48:10 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/13 20:00:30 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		add_to_compter(char my_block_i, t_compt *c)
{
	if (my_block_i == '#')
		((*c).dieze)++;
	if (my_block_i == '.')
		((*c).point)++;
	if (my_block_i == '\n')
		((*c).ligne)++;
	return (0);
}

static int		check_endline(char *b, int i, t_compt *c)
{
	if (b[i + 1] == '\0' || (b[i] == '\n' && b[i + 1] == '\n'))
	{
		if ((*c).ligne != 4 || (*c).dieze != 4 || (*c).point != 12)
			return (1);
		(*c).car = -1;
		(*c).ligne = 0;
		(*c).dieze = 0;
		(*c).point = 0;
	}
	else
		return (1);
	return (0);
}

int				filter_file(char *b, int i)
{
	t_compt		c;

	c.dieze = 0;
	c.point = 0;
	c.ligne = 1;
	c.car = 0;

	if (b[0] == '\0')
		return (1);
	while (b[i] != '\0')
	{
		if (b[i] != '\n' && b[i] != '.' && b[i] != '#')
			return (1);
		if (c.car < 19)
		{
			c.car++;
			add_to_compter(b[i], &c);
		}
		if (c.car == 19)
		{
			i++;
			if (check_endline(b, i, &c) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
