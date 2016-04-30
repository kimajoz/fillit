/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:54:00 by pbillett          #+#    #+#             */
/*   Updated: 2016/03/05 19:00:28 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int nombrepieces;
	char **tab_tot;
	int **all_tetriminos;
	int sizemap;

	nombrepieces = 0;
	if(check_usage(argc, argv, nombrepieces) == 1)
		exit(1);
	else // Si le fichier est verifie, je le resous
	{
		tab_tot = checkfile(openfile(argv[1]), &nombrepieces);
		all_tetriminos = create_all_tetriminos(tab_tot, nombrepieces);
		sizemap = get_square_root(nombrepieces);
		resolve_smallest_square(all_tetriminos, nombrepieces, sizemap);
	}
	return (0);
}
