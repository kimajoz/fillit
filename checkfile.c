/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/03 19:48:11 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1
#define BUF_FULL_SIZE 4096

int			checkfile(char* filename)
{
	int fd;
	int fd2;
	int ret;
	int ret2;
	char buf[BUF_SIZE + 1];
	char buf2[BUF_FULL_SIZE + 1];
	int compt;
	int checkcontent;
	char **resultpatern;
	char **contentarray;
	int i;
	int j;
	int comptblock;
	int comptdieze;
	int blocknumb;

	i = 0;
	j = 0;
	resultpatern = NULL;
	contentarray = NULL;
	checkcontent = 0;
	compt = 1;
	comptblock = 0;
	comptdieze = 0;
	blocknumb = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open failed\n");
		return (1);
	}

	// Check Number on line and characters by line:
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';

		// PAS DE CARACTERE DIFFERENTS DE \n . et #
		if (buf[0] != '\n' && buf[0] != '.' && buf[0] != '#')
			checkcontent = 1;

		// ON DECOUPE EN BLOC (tout les 21 caracteres)
		if (comptblock <= 21)
		{
			// jenregistre le bloc courant dans mon tableau
			contentarray[blocknumb][comptblock] = buf[0];
			comptblock++;
		}
		else
		{
			// je remet le compteur a zero
			comptblock = 0;
			blocknumb++;
		}
	}

	// ON VERIFIE LE NOMBRE DE CATACTERES #:
	while (i < blocknumb)
	{
		while (contentarray[i][j] != '\0')
		{
			//ft_putchar(contentarray[i][j]);
			if (contentarray[i][j] == '#')
				comptdieze++;
			j++;
		}
		if (comptdieze != 4)
		{
			ft_putstr("error wrong number of #");
			return (0);
		}
		i++;
	}

	// PAS DE LIGNE DE PLUS DE 4 CARACTERES
	if (buf[0] == '\n')
	{
		if (compt != 5) // Si la ligne compte plus de 4 caracteres
		{
			if (compt != 1) // Si la ligne compte plus de 1 caracteres
				checkcontent = 1;
				//ft_putnbr(compt);
				//ft_putstr("error\n");
		}
		compt = 0;
	}
	compt++;

	// Check Special patern on all:
	fd2 = open(filename, O_RDONLY);
	ret2 = read(fd2, buf2, BUF_FULL_SIZE);
	buf2[ret2] = '\0';
	
	// POUR AFFICHER LE CONTENU DU FICHIER (VIA LE BUFFER):
	ft_putstr(buf2);

	// PAS 2 LIGNES VIDES D'AFFILES
	resultpatern[0] = ft_strstr(buf2, "\n\n\n"); // Trois lignes d'affiles (en comptant le saut de ligne)
	
	// IL Y A QUE DES ESPACES VIDES (POINTS)
	
	// IL Y A UN NOMBRE DIFFERENTS DE 4#

	while (resultpatern != '\0')
	{
		if (resultpatern[i] == NULL || resultpatern[i] == buf2)
			ft_putstr("patern not found\n");
		else
		{
			ft_putstr("patern found !\n");
			checkcontent = 1;
		}
		i++;
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
