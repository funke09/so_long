#include <stdio.h>
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

void    print_map(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        ft_putstr_fd(map[i], 1);
        i++;
    }
}

int main(int ac, char *av[])
{
    t_long so_long;
    int ret;

    if (ac != 2)
    {
        // exit(1);
        showerror(&so_long, "error: usage ./so_long filename.");
    }
    if((ret=read_check(av[1], &so_long)) < 0){
        printf("%d\n", ret);
        return(ret);
    }
    print_map(so_long.map);
    // parsing(&so_long, av[1]); // check .ber // stock => **map
    // display(&so_long); // mlx ..
    return 0;
}