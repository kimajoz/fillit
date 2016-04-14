
#include "fillit.h"

int		resolve_smallest_square(int **all_tetriminos, int nombrepieces, int mapsize)
{
	int n;
	char **map;

	n = 0;
	ft_putstr("resolvesquare\n");
	map = ft_createmap(mapsize);
	ft_showmap(map, mapsize);
	resolvesquare(&all_tetriminos, nombrepieces, mapsize, map, n, 0, 0);
	return (0);
}
