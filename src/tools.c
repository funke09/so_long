

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
    if(c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P' || c == '\n' || c == 'N')
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

int	count_collec(t_long *var)
{
	int		row;
	int		col;

	row = 0;
	var->collect = 0;
	while (row < g_y)
	{
		col = 0;
		while (col < g_x)
		{
			if (var->map[row][col] == 'C')
				var->collect += 1;
			col++;
		}
		row++;
	}
	return (var->collect);
}

int	check_collect(t_long *var)
{
	if (count_collec(var) == 0)
    {
        ft_putstr_fd("\e[34m\e[1mCONGRATS\n!!!! You WON !!!!\e[0m\n", 1);
		ft_exit(var);
    }
	return (0);
}