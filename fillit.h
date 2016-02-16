/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:36:44 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/16 15:13:52 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUF_SIZE 527

char	*openfile(char* filename);
char	**checkfile(char* filecontent);
int		resolvesquare(char **filecontent);

#endif
