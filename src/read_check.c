
#include "../so_long.h"

int     count_lines(char *filename)
{
    int count;
    char    *line;
    int fd;

    count = 0;
    line = NULL;
    if ((fd = open(filename, O_RDONLY)) < 0)
        return (-1);
    while((line = get_next_line(fd)))
    {
        free(line);
        line = NULL;
        count++;
    }
    return(count);
}


int     read_check(char *filename, t_long *so_long)
{
    int i;
    int fd;
    char *line;
    int len;
    int y;

    i = 1;
    y = count_lines(filename);
    so_long->map = (char**)malloc(sizeof(char *) * (y + 1));
    if (!so_long->map)
        return (-3);
    line = NULL;
    if ((fd = open(filename, O_RDONLY)) < 0)
        return (-4);
    line = get_next_line(fd);
    if (!line || !full_wall(line))
        return (-1);
    len  = ft_strlen(line);
    so_long->map[0] = ft_strdup(line);
    free(line);
    while ((line = get_next_line(fd)))
    {
        int l = ft_strlen(line);
        if (line[l - 1] != '\n') // the last line 
        {
            if (l + 1 != len)
                return (-7);
            so_long->map[i++] = ft_strdup(line);
            free(line);
            break ;
        }
        if (len != ft_strlen(line))
            return (-2);
        if(!check_line(line))
            return(-6);
        so_long->map[i++] = ft_strdup(line);
        free(line);
    }
    so_long->map[i]= NULL;
    if (!full_wall(so_long->map[i - 1]))
                return(-5);
    return(1);
}