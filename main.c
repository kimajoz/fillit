/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:54:00 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/16 13:33:44 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		// Si le fichier est verifie, je le resous
		if (checkfile(openfile(argv[1])) == 0)
		{
			ft_putstr("ok file open\n");
			//resolvesquare(all_block);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit input_file\n");
	return (0);
}
