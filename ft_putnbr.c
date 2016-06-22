/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:00:04 by pbillett          #+#    #+#             */
/*   Updated: 2016/06/22 15:14:26 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putnbr(int n)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
