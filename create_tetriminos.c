

#include "fillit.h" 

int		*create_tetriminos(char *curblock, int numeropiece)
{
	int i;
	int y;
	int x;
	int m;
	int *piece;

	i = 0;
	y = 0;
	x = 0;
	m = 0;
	piece = malloc(8 * sizeof(int));// Malloc pour les 4 diezes (xy,xy,xy,xy,)
	while (curblock[i] != '\0')
	{
		if (curblock[i] == '#')
		{
				// On recupere sa position en x et y (on la deduit)
				y = (i / 5); //Soit 1 ligne (et pas ligne 0)
				//ft_putnbr(y);
				x = (i  % 5); //Soit 2 (soit 3 pieces) pour une piece situé en case 8 
				//ft_putnbr(x);
				// Sinon je la stocke dans un tableau pour l'inserer +tard
				piece[m++] = y;
				piece[m++] = x;
		}
		i++;
	}
	// On ajoute réellement la piece dans la map.
	ft_putstr(" piece ");
	ft_putnbr(numeropiece);
	ft_putstr(": ");
	ft_putlstnbr(piece, 8);
	ft_putstr("\n");
	//*totpiece = ft_addblock(piece, map, numeropiece);
	return (piece); // Si toutes les pieces rentrent bien dans la map, j'insere la piece, et je sors
}
