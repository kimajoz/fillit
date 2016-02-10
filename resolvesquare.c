/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/10 19:21:16 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		resolvesquare(char **filecontent)
{
	int n;
	int i;
	ft_putstr("resolvesquare");

	n = 0;
	i = 0;

	while (filecontent[n] != '\0')
	{
		/*
		while (filecontent[n][i] != '\0')
		{
			//ft_putchar(filecontent[n][i]);
			i++;
		}
		*/
		ft_putnbr(n);
		ft_putchar('\n');
		n++;
	}

	//if () // not succeed
	//	ft_putstr("error not resolvesquare");
	return (0);
}

