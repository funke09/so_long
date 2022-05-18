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
