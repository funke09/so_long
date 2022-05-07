

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

int check_line(char *line)
{
    int i;

    i = 1;
    if (line[0] != '1')
    {
        printf("err1");
        return (0);
    }
    while (line[i])
    {
        if (!is_valid(line[i]))
        {
            printf("err2");
            return (0);
        }
        i++;
    }
    if(line[i - 2] != '1')
    {
        printf("err3");
        return 0;
    }

    return (1);
}