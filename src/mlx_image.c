#include "../so_long.h"


void    load_image(t_long *so_long, int x, int y)
{
    // printf("x=%i y=%i\n", x, y);
    // // if(!)
    // printf("dkhlt\n");

    // if (!so_long)
    //     printf("map == NULL");
    if (so_long->map[y][x] == 'C')
        so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
        "images/coin.xpm", &so_long->x, &so_long->y);
    else if (so_long->map[y][x] == 'E')
        so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx,\
        "images/close_door.xpm", &so_long->x, &so_long->y);
    else if (so_long->map[y][x] == 'P')
        so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
        "images/princess.xpm", &so_long->x, &so_long->y);
    else if (so_long->map[y][x] == '1')
        so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
        "images/wall.xpm", &so_long->x, &so_long->y);
    else if (so_long->map[y][x] == '0')
        so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
        "images/space.xpm", &so_long->x, &so_long->y);
    mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, so_long->image, x * 50, y * 50);
    mlx_destroy_image(so_long->mlx_ptr.mlx, so_long->image);
}

void    print_map(t_long *so_long)
{
    int x = 0;
    int y = 0;
    // so_long->y = 0;
    printf("FIRST\n");
    while(y < g_y)
    {
        x = 0;
        while (x < g_x)
        {
            // printf("x=%i, y=%i\n", x, y);
            load_image(so_long, x, y);
            // printf("get_image end.\n");
            x++;
        }
       y++; 
    }
    printf("LAST\n");
}

void    pos_player(t_long *so_long)
{
    int i;
    int j;

    i = 0;
    while(i < g_y)
    {
        j = 0;
        while(j < g_x)
        {
            if(so_long->map[i][j] == 'P')
            {
                so_long->px = j;
                so_long->py = i;
            }
            j++;
        }
        i++;
    }
    
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    print_long(t_long *so_long)
{
    int i,j;
    i = 0;
    ft_putstr_fd("map: \n", 1);
    while (i < g_y)
    {
        j = 0;
         while (j < g_x)
         {
             ft_putchar_fd(so_long->map[i][j], 1);
             j++;
         }
         ft_putchar_fd('\n', 2);
         i++;
    }
    ft_putstr_fd("sadfdsaf", 1);
    if (!so_long->mlx_ptr.mlx || !so_long->mlx_ptr.win)
    {
        ft_putstr_fd("mlx_ptr = null", 1);
        exit(1);
    }
    printf("x=%d, y=%d\n", so_long->px, so_long->py);
    printf("game: moves=%d collectibles=%d\n", so_long->move, so_long->collect);
}

int 	deal_key(int key, t_long *so_long)
{
    // printf("deal key entred\n");
    if (key == ESC)
	{
        ft_putstr_fd("\e[33m\e[1mGame closed! (ESC)\e[0m\n", 1);
		ft_exit(so_long);
	}
    else
    {

        printf("f\n");
        // print_long(so_long);
        movements(key, so_long);
        printf("l\n");
    }
    print_map(so_long);
	return 0;
}

int ft_expose(t_long *so_long)
{
    print_map(so_long);
    return (0);
}

void    my_mlx(t_long *so_long)
{
    t_data img;

    so_long->mlx_ptr.mlx = mlx_init();
	so_long->mlx_ptr.win = mlx_new_window(so_long->mlx_ptr.mlx, g_x * 50, g_y * 50, "Hello world!");
	img.img = mlx_new_image(so_long->mlx_ptr.mlx, g_x * 50, g_y * 50);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,\
	// &img.endian);
    
    ft_putstr_fd("debug1", 2);
    pos_player(so_long);
    ft_putstr_fd("debug2", 2);
    count_collec(so_long);
    ft_putstr_fd("debug3", 2);
    print_map(so_long); // print
    print_long(so_long);
    mlx_hook(so_long->mlx_ptr.win, X_EVENT_KEY_PRESS, 1L << 0, deal_key, so_long);
	// mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
    mlx_expose_hook(so_long->mlx_ptr.win, ft_expose, so_long);
    // mlx_key_hook(so_long->mlx_ptr.win, deal_key, (void *)so_long);
	mlx_loop(so_long->mlx_ptr.mlx);
}
