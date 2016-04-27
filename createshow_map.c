
#include "fillit.h"

char     **ft_createmap(int mapsize)
{
        int y;
        int x;
        char **map;

        y = 0;
        x = 0;
        ft_putstr("Je cree la map\n");
        map = (char **)malloc(mapsize * sizeof(char *));
        while (y < mapsize)        
		{                
			map[y] = (char *)malloc(mapsize * sizeof(char));
			while(x < mapsize)
			{
					map[y][x] = '.';
					x++;
			}
			x = 0;
			y++;
        }
        //ft_putstr("Je montre nouvelle map fraiche\n");
        //ft_showmap(map, mapsize);
        return(map);
}

int              ft_showmap(char **map, int mapsize)
{
        int i;
        int j;

        i = 0;
        j = 0;
        ft_putstr("I show the map :");
        //ft_putnbr(mapsize);
		//ft_putnbr(i);
		//ft_putnbr(j);
        ft_putchar('\n');
        while (j < mapsize)
        {
			//ft_putstr("test");
			while (i < mapsize) 
			{
				// Attention ici il faut mettre un \0 lors de l'allocation si on avait voulu s'arreter a la fin de la chaine de caracteres sous cette condition.
				//ft_putchar('a');
				//ft_putnbr(i);
				//ft_putnbr(j);
				ft_putchar(map[j][i]);
				i++;
			}
			ft_putchar('\n');
			i = 0;
			j++;
        }
        return (0);
}

