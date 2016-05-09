/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/05/09 11:22:48 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		checktouch(char *block)
{
	int			i;
	int			touchotherdieze;

	i = 0;
	touchotherdieze = 0;
	while (block[i] != '\0')
	{
		if (block[i] == '#')
		{
			if ((block[i - 1] == '#') && (i > 0 && i < 19))
				touchotherdieze++;
			if ((block[i + 1] == '#') && (i < 19))
				touchotherdieze++;
			if ((block[i - 5] == '#') && (i > 4))
				touchotherdieze++;
			if ((block[i + 5] == '#') && (i < 15))
				touchotherdieze++;
		}
		i++;
	}
	if (touchotherdieze != 6 && touchotherdieze != 8)
		return (1);
	return (0);
}

static int		ft_blocknumb(char *filecontent)
{
	int			blocknumb;
	int			i;

	i = 0;
	blocknumb = 0;
	while (filecontent[i] != '\0')
	{
		if ((filecontent[i] == '\n') && (filecontent[i + 1] == '\n' ||
					filecontent[i + 1] == '\0'))
			blocknumb++;
		i++;
	}
	return (blocknumb);
}

static char		**createblocks(int **blocknumb)
{
	char		**all_block;
	int			i;

	i = 0;
	all_block = (char **)malloc(**blocknumb * sizeof(char*));
	if (all_block == NULL)
		return (NULL);
	while (i < **blocknumb)
	{
		all_block[i] = malloc(20);
		if (all_block[i] == NULL)
			return (NULL);
		i++;
	}
	return (all_block);
}

static char		**fillblocks(char **all_block, char *filecontent)
{
	int			i;
	int			a;
	int			n;

	i = 0;
	a = 0;
	n = 0;
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
	return (all_block);
}

char			**checkfile(char *filecontent, int *blocknumb)
{
	int			n;
	int			i;
	int			car;
	int			ligne;
	char		**all_block;

	n = 0;
	i = 0;
	car = 0;
	ligne = 1;
	if (filter_file(filecontent, i, car, ligne) != 0)
		return (0);
	*blocknumb = ft_blocknumb(filecontent);
	all_block = createblocks(&blocknumb);
	all_block = fillblocks(all_block, filecontent);
	while (n < *blocknumb)
	{
		if (checktouch(all_block[n]) != 0)
			return (NULL);
		n++;
	}
	return (all_block);
}
