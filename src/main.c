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


int main(int ac, char **av)
{ 
    int ret;
    t_long so_long;

    if (ac != 2)
    {
        // exit(1);
        showerror(&so_long, "error: usage ./so_long filename.");
    }
    if((ret=read_check(av[1], &so_long)) < 0){
        printf("%d\n", ret);
        return(ret);
    }
    // printf("%s\n", "hhhhh");
    printf("gx=%i gy=%i\n", g_x, g_y);
    // ft_putstr_fd("sdfdsf0", 2);
    // print_long(&so_long);
    // ft_putstr_fd("sdfdsf1", 2);
    // printf("sfdsf");
    my_mlx(&so_long);
    return 0;
}