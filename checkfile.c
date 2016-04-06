/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/24 17:14:11 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		filter_file(char *my_block)
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
			return (1);
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
		return (1);
	}
	return (0);
}

static int		checktouch(char *block, int numpiece)
{
	int i;
	int touchotherdieze;

	i = 0;
	touchotherdieze = 0;

	ft_putstr("piece number");
	ft_putnbr(numpiece);
	ft_putchar('\n');

	// ON VERIFIE LE NOMBRE DE CATACTERES # QUI SE TOUCHENT:
	while (block[i] != '\0')
	{
		//ft_putchar(block[i]);
		//ft_putnbr(touchotherdieze);
		if (block[i] == '#')
		{
			if ((block[i - 1] == '#') && (i > 0 && i < 19))
			{
				touchotherdieze++;
				ft_putstr("touch before:");
				ft_putnbr(touchotherdieze);
				ft_putchar('\n');
			}
			if ((block[i + 1] == '#') && (i < 19))
			{
				touchotherdieze++;
				ft_putstr("touch after:");
				ft_putnbr(touchotherdieze);
				ft_putchar('\n');
			}
			if ((block[i - 5] == '#') && (i > 4))
			{
				touchotherdieze++;
				ft_putstr("touch line before:");
				ft_putnbr(touchotherdieze);
				ft_putchar('\n');
			}
			if ((block[i + 5] == '#') && (i < 15))
			{
				touchotherdieze++;
				ft_putstr("touch line after:");
				ft_putnbr(touchotherdieze);
				ft_putchar('\n');
			}
		}
		i++;
	}
	if (touchotherdieze != 6 && touchotherdieze != 8) //les carres des triominos se touche au moins 6 fois ou 8 pour le carre.
	{
		ft_putstr("error bad touch between #");
		ft_putnbr(touchotherdieze);
		ft_putchar('\n');
		ft_putstr("piece number");
		ft_putnbr(numpiece);
		ft_putchar('\n');
		return (1);
	}
	return(0);
}

static int		ft_blocknumb(char *filecontent)
{
	int blocknumb;
	int i;

	i = 0;
	blocknumb = 0;
	// Je compte le nombre de blocs:
	while (filecontent[i] != '\0')
	{
		if ((filecontent[i] == '\n') && (filecontent[i + 1] == '\n' || filecontent[i + 1] == '\0')) // Attention d'etre logiaue et propre pour calculer le nombre de bloc !!! Un nbr de bloc mauvais peut forcement rendre tout le reste des scripts mauvais.
			{
				blocknumb++;
			}
		i++;
	}
	//ft_putendl("toto");
	return (blocknumb);
}

char	**checkfile(char *filecontent, int *blocknumb)
{
	int i;
	int a;
	int n;
	char **all_block;

	i = 0;
	a = 0;
	n = 0;

	// Je filtre mon fichier
	if (filter_file(filecontent) != 0)
	{
		ft_putstr("Bad filter_file\n");
		return (NULL);
	}

	// Je compte le nombre de blocs:
	//ft_putnbr(ft_blocknumb(filecontent));
	*blocknumb = ft_blocknumb(filecontent);

	// Je fais mes mallocs:
	i = 0;
	//ft_putnbr(*blocknumb);
	all_block = (char **)malloc(*blocknumb * sizeof(char*));
	
	if (all_block == NULL)
		return (NULL);
	while (i <= *blocknumb)
	{
		all_block[i] = malloc(21);
		if (all_block[i] == NULL)
			return (NULL);
		i++;
	}
	ft_putstr("malloc ok\n");

	// J'enregistre chaque bloc dans un tableau:
	i = 0;
	while (filecontent[i] != '\0')
	{
		all_block[n][a] = filecontent[i];
		if (a < 20)
			a++;
		else
		{
			if ((filecontent[i] == '\n' && filecontent[i - 1] == '\n'))
				n++;
			a = 0;
		}
		i++;
	}
	ft_putstr("bloc saved in tab ok\n");

	// Je verifie que les blocks de tetriminos se touchent 
	n = 0;
	while (n < *blocknumb)
	{
		if (checktouch(all_block[n], n) != 0)
			return (NULL);
		n++;
	}
	ft_putstr("check touch ok\n");
	
	return (all_block);
}
