/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:44:57 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/09 16:07:23 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		resolvesquare(char ***triominosArray)
{
	int i;
	ft_putstr("resolvesquare");

	i= 0;
	while (triominosArray[i] != '\0')
	{
		ft_putnbr(i);
		i++;
	}
	//if () // not succeed
	//	ft_putstr("error not resolvesquare");
	return (0);
}

