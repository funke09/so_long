

#include "../so_long.h"

int full_wall(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] == '\n')
        {
            i++;
            continue ;
        }
        if(line[i] != '1')
            return(0);
        i++;
    }
    return(1);
}


int is_valid(char c)
{
    if(c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P' || c == '\n')
        return(1);
    return(0);
}

void fill_symbol(char c)
{
    if (c == 'P')
        g_symbol[POS] += 1;
    else if (c == 'C')
        g_symbol[COLL] += 1;
    else if (c == 'E')
        g_symbol[EXT] += 1;
}

int check_line(char *line)
{
    int i;

    i = 1;
    if (line[0] != '1')
        return (0);
    while (line[i])
    {
        if (!is_valid(line[i]))
            return (0);
        else if(line[i] == 'P' || line[i] == 'C' || line[i] == 'E')
            fill_symbol(line[i]);
        i++;
    }
    if(line[i - 2] != '1')
        return 0;
    return (1);
}