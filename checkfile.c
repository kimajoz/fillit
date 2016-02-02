/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/02 19:35:11 by pbillett         ###   ########.fr       */
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

	compt = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open failed\n");
		return (1);
	}
	// do something like show content
	ft_putstr("ok file open\n");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		//ft_putnbr(ret);
		//ft_putchar('\n');
		ft_putstr(buf);
		//ft_putstr("end\n");
		if (buf[0] == '\n')
		{
			if (compt != 5)
				ft_putnbr(compt);
				ft_putstr("error on line\n");
			//ft_putstr("sp\n");
			compt = 0;
		}
		compt++;
	}

	if (close(fd))
	{
		ft_putstr("close() failed\n");
	}
	return (0);
}
