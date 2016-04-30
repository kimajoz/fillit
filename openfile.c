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
		return (NULL);//ft_putstr("open failed\n");
	buf = ft_memalloc(BUF_SIZE + 1);
	ret = read(fd, buf, BUF_SIZE); //show content //ft_putstr("ok file open\n");
	buf[ret] = '\0';
	return (buf);
	if (close(fd))	
		return (NULL);//ft_putstr("close() failed\n");
}
