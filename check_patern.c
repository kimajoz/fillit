/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_patern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbillett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 19:50:55 by pbillett          #+#    #+#             */
/*   Updated: 2016/02/09 21:26:01 by pbillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_patern(char *str)
{
	int i;

	i = 19; // Il existe 19 formes de tetriminos differents
	char *patern[19];

	//Barres
	patern[0] = "####";
	patern[1] = "#...#...#...#";
	//Carre
	patern[2] = "##..##";
	// Z et inverse
	patern[3] = "##...##";
	patern[4] = "#..##..#";
	patern[5] = "##.##";
	patern[6] = "#...##...#";

	// T et inverse
	patern[7] = "#..###";
	patern[8] = "###..#";
	patern[9] = "#...##..#";
	patern[10] = "#..##...#";

	// L
	patern[11] = "###.#";
	patern[12] = "#.###";
	patern[13] = "#...#...##";
	patern[14] = "##...#...#";

	// L inverse
	patern[15] = "###...#";
	patern[16] = "#...###.";
	patern[17] = "##..#...#";
	patern[18] = "#...#..##";

	while (i > 0)
	{
		if (str == patern[i])
			return(i);
		i--;
	}

	return (0);
}
