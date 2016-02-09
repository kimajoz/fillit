/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/09 18:44:20 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1

int			checkfile(char* filename)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	int checkcontent;
	char ***contentarray;
	int i;
	int j;
	int k;
	int comptdieze;
	int comptpoint;
	int blocknumb;
	int ligne;
	int car;
	int cartot;
	int touchotherdieze;

	ligne = 0;
	car = 0;
	i = 0;
	j = 0;
	k = 0;
	checkcontent = 0;
	comptdieze = 0;
	comptpoint = 0;
	blocknumb = 0;
	touchotherdieze = 0;
	cartot = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open failed\n");
		return (1);
	}

	/*
	ft_putstr("cartot:");
	ft_putnbr(cartot);
	ft_putchar('\n');
	*/
	
	ft_putstr("\nNew block:");
	ft_putnbr(blocknumb);
	ft_putchar('\n');

	contentarray = malloc(blocknumb * sizeof(char **));

	if (contentarray == NULL)
		return(0);

	// Check Number on line and characters by line:
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';

		// PAS DE CARACTERE DIFFERENTS DE \n . et #
		if (buf[0] != '\n' && buf[0] != '.' && buf[0] != '#')
			checkcontent = 1;

		ft_putstr(buf);

		// ON DECOUPE EN BLOC (tout les 20 caracteres + 1 de saut a la ligne)
		if (cartot < 20)
		{
			//ft_putstr(buf);
			//ft_putstr("inbetween");
			//ft_putnbr(car);
			//ft_putnbr(cartot);

			if ((buf[0] == '#' || buf[0] == '.') && car < 4)
			{
				//ft_putstr("test");
				//contentarray[blocknumb][ligne][car] = buf[0];
				if (buf[0] == '#')
				{
					comptdieze++;
					//ft_putstr("comptdieze");
				}
				if (buf[0] == '.')
					comptpoint++;
				car++;
				//ft_putnbr(car);
			}
			else if (buf[0] == '\n' && car == 4)
			{
				car++;
				//contentarray[blocknumb][ligne][car] = buf[0];
				ligne++;
				cartot = car + cartot;
				car = 0;
				//ft_putstr("cartot:");
				//ft_putnbr(cartot);
				//ft_putchar('\n');
			}
			else
			{
				ft_putstr("error car\n");
				ft_putstr("cartot:\n");
				ft_putnbr(cartot);
				ft_putnbr(car);
				ft_putstr(buf);
				ft_putchar('\n');
				return (0);
			}
		}
		else
		{
			if (buf[0] == '\n' && car == 0)
			{
				if (ligne != 4 || comptdieze != 4 || comptpoint != 12)
				{
					ft_putstr("error numb:\n");
					ft_putnbr(ligne);
					ft_putchar('\n');
					ft_putnbr(comptdieze);
					ft_putchar('\n');
					ft_putnbr(comptpoint);
					ft_putchar('\n');
					return (0);
				}
				// je remet les compteurs a zero
				cartot = 0;
				car = 0;
				ligne = 0;
				comptdieze = 0;
				comptpoint = 0;
				blocknumb++;
				ft_putstr("\nNew block:");
				ft_putnbr(blocknumb);
				ft_putchar('\n');
			}
			else
			{
				//wrong number of inbetween line
				ft_putstr("error wrong number of inbetween line");
			}
		}
	}

	/*
	// ON VERIFIE LE NOMBRE DE CATACTERES # QUI SE TOUCHENT:
	while (i < blocknumb)
	{
		while (j != '\0')
		{
			//ft_putchar(contentarray[i][j][k]);

			while (k != '\n')
			{
				if (contentarray[i][j][k] == '#')
				{
					if ((contentarray[i][j][k - 1] == '#') && (k >= 1 && k <= 3))
						touchotherdieze++;
					if ((contentarray[i][j][k + 1] == '#') && (k >= 0 && k <= 2))
						touchotherdieze++;
					if ((contentarray[i][j - 1][k] == '#') && (j >= 1 && j <= 3))
						touchotherdieze++;
					if ((contentarray[i][j + 1][k] == '#') && (j >= 0 && j <= 2))
						touchotherdieze++;
				}
				k++;
			}
			j++;
			k = 0;
		}
		if (touchotherdieze != 6 && touchotherdieze != 8) //les carres des triominos se touche au moins 6 fois ou 8 pour le carre.
		{
			ft_putstr("error bad touch between #");
			return (0);
		}
		i++;
	}
	*/

	if (checkcontent == 0)
	{
		ft_putstr("ok file open\n");
		//resolvesquare(contentarray);
	}
	else
		ft_putstr("error\n");

	if (close(fd))
	{
		ft_putstr("close() failed\n");
	}
	return (0);
}
