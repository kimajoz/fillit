
#include "fillit.h"

int	check_usage(int argc, char **argv, int nombrepieces)
{
	if (argc == 2)
        {
                if (openfile(argv[1]) == NULL)
                {
                        ft_putstr("fillit: impossible d'évaluer «");
                        ft_putstr(argv[1]);
                        ft_putstr("»: Aucun fichier ou dossier de ce type\n");
                        return 1;;
                }
                if (checkfile(openfile(argv[1]), &nombrepieces) != NULL)// Si le fichier est verifie, je le resous
			return (0);
                else
		{
                        ft_putstr("error\n");
                        return (1);
                }
        }
        else
        {
                ft_putstr("usage: ./fillit input_file\n");
                return (1);
        }
	return (0);
}
