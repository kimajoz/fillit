/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square_root.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:47:19 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/02 18:47:36 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			get_square_root(int nombrepieces)
{
	int		total;
	int		square_root;
	int		i;

	total = 4 * nombrepieces;
	square_root = 0;
	i = 0;
	while (square_root < total)
	{
		i++;
		square_root = i * i;
	}
	return (i);
}
