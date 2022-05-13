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



int main(int ac, char **av)
{ 
    t_long so_long;
	// t_data	img;

    (void)ac;
    (void)av;

    // t_long image;
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
    printf("%s\n", "hhhhh");
    printf("x=%i y=%i\n", g_x, g_y);
    my_mlx(&so_long);
    // printf("%s\n", "hhhhh2");
    // get_image(&so_long);

    // check_image(so_long.map, &so_long);
    // pos_player(&so_long, so_long.map);


    // print_map(so_long.map);
    // printf("x=%i y=%i", g_x, g_y);

    // mlx_ptr = mlx_init();
    // win_ptr = mlx_new_window(mlx_ptr, 500, 500, "my_window");
	// image = mlx_new_image(mlx_ptr, 500, 500);

    // int pixel_bites;
    // int line_bites;
    // int endian;
    // int *buffer = (int *)mlx_get_data_addr(image, &pixel_bites, &line_bites, &endian);
    // int color = 0xABCDEF;
    
    // if (pixel_bites != 32)
    //     color = mlx_get_color_value(mlx_ptr, color);
    // for(int y = 0; y < 500; ++y)
    // {
    //     for(int x = 0; x < 500; ++x)
    //     {
            
    //         int pixel = (y * 500) + x;
    //         buffer[pixel] = convert_color(0xff0000, endian);
    //         // printf("%d\n", );

    //     }
    // }
    // mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
    // mlx_loop(mlx_ptr);
    // return(0);
    // parsing(&so_long, av[1]); // check .ber // stock => **map
    // display(&so_long); // mlx ..
    return 0;
}