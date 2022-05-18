
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

int    read_first(char *filename, t_long *so_long, char **line, int *len)
{
    g_y = count_lines(filename);
    so_long->map = (char**)malloc(sizeof(char *) * (g_y + 1));
    if (!so_long->map)
        return (-3);
    *(line) = NULL;
    if ((g_fd = open(filename, O_RDONLY)) < 0)
        return (-4);
    *(line) = get_next_line(g_fd);
    if (!*(line) || !full_wall(*(line)))
        return (-1);
    *len = ft_strlen(*(line));
    so_long->map[0] = ft_strndup(*(line), (*len) - 1);
    free(*(line));
    line = NULL;
    // ft_putendl_fd(so_long->map[0], 2);
    return (1);
}

int    read_last(int *i, t_long *so_long, int *len)
{
    if (!full_wall(so_long->map[*i - 1]))
                return(-5);
    if (g_symbol[POS] != 1 || g_symbol[COLL] < 1 || g_symbol[EXT] > 1)
        return (-8);
    g_x = (*len) - 1;
    return (1);
}

int check_if_last_line(char *line, t_long *so_long, int *i, int *len)
{
     int l;
     
    l = ft_strlen(line);
    if (line[l - 1] != '\n') // the last line 
    {
        if (l + 1 != *len)
            return (-7);
        so_long->map[(*i)++] = ft_strndup(line, l - 1);
        free(line);
        return (1);
    }
    return (0);
}

int     read_check(char *filename, t_long *so_long)
{
    int i;
    char *line;
    int len;

    i = 1;
    line = NULL;
    len = 0;
    if ((read_first(filename, so_long, &line, &len)) < 0)
        return (-1);
    while ((line = get_next_line(g_fd)))
    {
        // ft_putstr_fd(line, 2);
        if (check_if_last_line(line, so_long, &i, &len) > 0)
            break ;
        if (len != (int)ft_strlen(line))
            return (-2);
        if(!check_line(line))
            return(-6);
        so_long->map[i] = ft_strndup(line, len - 1);
        // ft_putendl_fd(so_long->map[i], 2);
        free(line);
        line = NULL;
        i++;
    }
    // so_long->map[i]= NULL;
    if ((read_last(&i, so_long, &len)) < 0)
        return (-2);
    // print_long(so_long);
    return(1);
}