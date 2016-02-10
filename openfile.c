/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/10 12:09:50 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*openfile(char* filename)
{
	int fd;
	int ret;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		//ft_putstr("open failed\n");
		return (NULL);
	}
	buf = ft_memalloc(BUF_SIZE + 1);
	// do something like show content
	//ft_putstr("ok file open\n");
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	/*
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putstr(buf);
	ft_putstr("test");
	*/
	return (buf);

	if (close(fd))
	{
		//ft_putstr("close() failed\n");
		return (NULL);
	}
	//return (NULL);
}
