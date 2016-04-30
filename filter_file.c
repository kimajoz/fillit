
static int              check_number_of_hash(int comptdieze, int comptpoint, int ligne)
{
        if (ligne != 4 || comptdieze != 4 || comptpoint != 12)
                return (1);
        return 0;
}

static int              filter_file_while(char *my_block, int i, int comptdieze, int comptpoint, int car, int ligne){
        while (my_block[i] != '\0')
        {
                if (my_block[i] != '\n' && my_block[i] != '.' && my_block[i] != '#')
                        return(1);
                if (my_block[i + 1] == '\0' || (my_block[i] == '\n' && my_block[i - 1] == '\n'))
                {
                        if (check_number_of_hash(comptdieze, comptpoint, ligne) == 1)
                                return 1;
                        car = -1;
                        ligne = 0;
                        comptdieze = 0;
                        comptpoint = 0;
                }
                if (car < 19)
                {
                        car++;
                        if (my_block[i] == '#')
                                comptdieze++;
                        if (my_block[i] == '.')
                                comptpoint++;
                        if (my_block[i] == '\n')
                                ligne++;
                }
                i++;
        }
        return 0;
}

int              filter_file(char *my_block)
{
        int comptdieze;
        int comptpoint;
        int car;
        int i;
        int ligne;

        i = 0;
        car = 0;
        comptdieze = 0;
        comptpoint = 0;
        ligne = 1;
        if (filter_file_while(my_block, i, comptdieze, comptpoint, car, ligne) == 1)
                return 1;
        return (0);
}
