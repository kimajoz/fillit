
#include "fillit.h"

static char             **increase_mapsize(char **map, int mapsize)
{
        int m;

        m = 0;
        while (m < (mapsize - 1)) // je supprime toute ma carte precedente
        {
                free(map[m]);
                m++;
        }
        free(map);
        m = 0;
        mapsize++;
        map = ft_createmap(mapsize);
        return (map);
}

int             resolve_smallest_square(int **all_tetriminos, int nombrepieces, int mapsize)
{
        int n;
        char **map;

        n = 0;
    map = ft_createmap(mapsize);
        while (resolvesquare(&all_tetriminos, nombrepieces, map, n, mapsize) != 1)
                        map = increase_mapsize(map, mapsize++);
        ft_showmap(map, mapsize);
        return (0);
}
