/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/10 19:21:19 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		filter_file(char *my_block)
{
	int comptdieze;
	int comptpoint;
	int ligne;
	int car;
	int cartot;
	int i;

	i = 0;
	ligne = 0;
	car = 0;
	comptdieze = 0;
	comptpoint = 0;
	cartot = 0;

	// PAS DE CARACTERE DIFFERENTS DE \n . et #
	if (my_block[i] != '\n' && my_block[i] != '.' && my_block[i] != '#')
		return(1);

	if ((my_block[i] == '#' || my_block[i] == '.') && car < 4)
	{
		if (my_block[i] == '#')
			comptdieze++;
		if (my_block[i] == '.')
			comptpoint++;
		car++;
	}
	else if (my_block[i] == '\n' && car == 4)
	{
		car++;
		ligne++;
		cartot = car + cartot;
		car = 0;
	}
	else if (my_block[i] == '\n' && car == 0)
	{
		if (ligne != 4 || comptdieze != 4 || comptpoint != 12)
			return (0);
		// je remet les compteurs a zero
		cartot = 0;
		car = 0;
		ligne = 0;
		comptdieze = 0;
		comptpoint = 0;
	}
	else
	{
		ft_putstr("error wrong number of inbetween line");
		return(1);
	}
	return (0);
}

int		checktouch(char *block)
{
	int i;
	int touchotherdieze;

	i = 0;
	touchotherdieze = 0;

	// ON VERIFIE LE NOMBRE DE CATACTERES # QUI SE TOUCHENT:
	while (block[i] != '\0')
	{
		if (block[i] == '#')
		{
			if ((block[i - 1] == '#') && (i > 0 && i < 19))
				touchotherdieze++;
			if ((block[i + 1] == '#') && (i < 19))
				touchotherdieze++;
			if ((block[i - 5] == '#') && (i > 5))
				touchotherdieze++;
			if ((block[i + 5] == '#') && (i < 15))
				touchotherdieze++;
		}
		i++;
	}
	if (touchotherdieze != 6 && touchotherdieze != 8) //les carres des triominos se touche au moins 6 fois ou 8 pour le carre.
	{
		ft_putstr("error bad touch between #");
		return (0);
	}
	return(1);
}

int			checkfile(char* filecontent)
{
	int checkcontent;
	int i;
	int a;
	int n;
	int blocknumb;
	char **all_block;

	i = 0;
	a = 0;
	n = 0;
	checkcontent = 0;
	blocknumb = 0;

	// Je filtre mon tableau
	filter_file(filecontent);

	// Je compte le nombre de blocs:
	while (filecontent[i] != '\0')
	{
		if (filecontent[i] == '\n' && filecontent[i - 1] == '\n')
			blocknumb++;
		i++;
	}

	// Je fais mes mallocs:
	i = 0;
	all_block = malloc(blocknumb * sizeof(char*));
	while (i < blocknumb)
	{
		all_block[i] = malloc(21);
		i++;
	}

	// J'enregistre chaque bloc dans un tableau:
	i = 0;
	while (filecontent[i] != '\0')
	{
		ft_putchar(filecontent[i]);
		all_block[n][a] = filecontent[i];
		if (a < 21)
			a++;
		else
		{
			if (filecontent[i] == '\n' && filecontent[i - 1] == '\n')
				n++;
			a = 0;
		}
		i++;
	}

	// Je verifie que les blocks de tetriminos se touchent 
	n = 0;
	while (n < blocknumb)
	{
		checktouch(all_block[n]);
		n++;
	}

	// Je retourne les erreurs ou je termine ma fonction
	if (checkcontent == 0)
	{
		ft_putstr("ok file open\n");
		resolvesquare(all_block);
	}
	else
		ft_putstr("error\n");
	
	return (0);
}

