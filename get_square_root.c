#include "fillit.h"


int		get_square_root(int nombrepieces)
{
	int total;
	int square_root;
	int i;

	total = 4 * nombrepieces;
	square_root = 0;
	i = 0;
	while (square_root < total)
	{
		i++;
		square_root = i * i;
	}
	return (i);
}
