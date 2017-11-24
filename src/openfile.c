/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:42 by pbillett          #+#    #+#             */
/*   Updated: 2016/06/22 15:24:34 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		*openfile(char *filename)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = ft_memalloc(BUF_SIZE + 1);
	ret = read(fd, buf, BUF_SIZE);
	if (buf[ret] != '\0')
		return (NULL);
	buf[ret] = '\0';
	return (buf);
	if (close(fd))
		return (NULL);
}
