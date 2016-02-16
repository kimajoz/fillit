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

int		resolvesquare(char **filecontent)
{
	int n;
	int i;
	int map;
	ft_putstr("resolvesquare");

	n = 0;
	i = 0;
	map = 0;

	while (filecontent[i])
	{
		//ft_getsmallestsquare(map, numpiece, tab);
		/*
		while (filecontent[n][i] != '\0')
		{
			//ft_putchar(filecontent[n][i]);
			i++;
		}
		*/
		ft_putnbr(n);
		ft_putstr(filecontent[n]);
		ft_putchar('\n');
		n++;
	}

	//if () // not succeed
	//	ft_putstr("error not resolvesquare");
	return (0);

	//return (map, alphabet, piece);
}

