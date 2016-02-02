/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/02 20:19:59 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1

int			checkfile(char* filename)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	int compt;
	int checkcontent;

	checkcontent = 0;
	compt = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open failed\n");
		return (1);
	}
	// do something like show content
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		//ft_putnbr(ret);
		//ft_putchar('\n');
		// POUR AFFICHER LE CONTENU DU FICHIER (VIA LE BUFFER):
		//ft_putstr(buf);
		//ft_putstr("end\n");

		// PAS DE CARACTERE DIFFERENTS DE \n . et #
		if (buf[0] != '\n' && buf[0] != '.' && buf[0] != '#')
			checkcontent = 1;

		// PAS 2 LIGNE VIDES D'AFFILE

		// PAS DE TETRIMINO QUI NE TOUCHE AUCUN DES COTES (soit la forme du carre au centre)

		// PAS DE LIGNE DE PLUS DE 4 CARACTERES
		if (buf[0] == '\n')
		{
			if (compt != 5)
			{
				if (compt != 1)
					checkcontent = 1;
					//ft_putnbr(compt);
					//ft_putstr("error\n");
			}
			compt = 0;
		}
		compt++;
	}
	if (checkcontent == 0)
		ft_putstr("ok file open\n");
	else
		ft_putstr("error\n");

	if (close(fd))
	{
		ft_putstr("close() failed\n");
	}
	return (0);
}
