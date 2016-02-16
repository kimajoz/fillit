/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:54:00 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/16 18:41:17 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char **tab_tot;

	if (argc == 2)
	{
		// Si le fichier est verifie, je le resous
		tab_tot = checkfile(openfile(argv[1]));
		if (tab_tot != NULL)
		{
			ft_putstr("ok file open\n");
			//resolvesquare(tab_tot, numpiece);
			resolvesquare(tab_tot);
			//ft_tabdel(tab_tot); // Utiliser plutot une fonction aui free tout recursivement
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit input_file\n");
	return (0);
}
