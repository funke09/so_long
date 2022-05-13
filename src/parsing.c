#include "../so_long.h"

int check_extension(char *filename)
{
    int i;

    i = 0;
    while (filename[i])
        i++;
    if (i <= 4)
        return (-1);
    if (filename[i - 1] != 'r' || filename[i - 2] != 'e' || filename[i - 3] != 'b'
        || filename[i - 4] != '.')
        return (-1);
    return (0);
}

int    parsing(t_long *so_long, char *filename)
{
    if (check_extension(filename) < 0)
        return (-1);
    //get_x_y
    //stock map
    //check_map
    return (0);
}