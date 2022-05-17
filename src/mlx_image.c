#include "../so_long.h"


void    get_image(t_long *so_long, int x, int y)
{
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
}

void    check_image(char **map, t_long *so_long)
{
    int x = 0;
    int y = 0;
    // so_long->y = 0;
    while(y < g_y)
    {
        x = 0;
        while (x < g_x)
        {
            get_image(so_long, x, y);
            if (so_long->image == NULL)
                printf("null image\n");
            if (map[y][x] == '0')
                mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win,\
                so_long->image, x * 50, y * 50);
            if (map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
				so_long->image, x * 50, y * 50);
            if (map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
				so_long->image, x * 50, y * 50);
            if (map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
				so_long->image, x * 50, y * 50);
            if (map[y][x] == 'E')
				mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
				so_long->image, x * 50, y * 50);
            mlx_destroy_image(so_long->mlx_ptr.mlx, so_long->image);
            x++;
        }
       y++; 
    }
}

void    pos_player(t_long *so_long, char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P')
            {
                so_long->px = i;
                so_long->py = j;
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

int 	deal_key(int key, t_long *so_long)
{
    (void) key;
	// ft_putchar_fd('z', 1);
    printf("%d\n", key);
    // printf("px=%d py=%d\n", so_long->px, so_long->py);
    if(key == ESC)
        ft_exit(so_long);
    // if(key == W_KEY) // up 
    // {
    // }
    // else if(key == S_KEY) // down
    // {
    //     if(so_long->map[so_long->py - 1][so_long->px] != '1')
    //     {
    //         if(so_long->map[so_long->py - 1][so_long->px] == 'C')
    //         {
    //             so_long->collect += 1;
    //             so_long->px++;
    //         }
    //         if(so_long->map[so_long->py - 1][so_long->px] != 'E')
    //         {
    //             so_long->map[so_long->px + 1][so_long->py] = 'P';
    //             so_long->map[so_long->px][so_long->py] = '0';
    //             // so_long->px++;
    //         }
    //     }
    //     so_long->move++;
    // }
    else if(key == A_KEY) // left
    {
        printf("a");
    }
    else if(key == D_KEY) // right
    {
        printf("d");
    }
    check_image(so_long->map, so_long);
	return 0;
}

void    my_mlx(t_long *so_long)
{
    t_data img;

    so_long->mlx_ptr.mlx = mlx_init();
	so_long->mlx_ptr.win = mlx_new_window(so_long->mlx_ptr.mlx, g_x * 50, g_y * 50, "Hello world!");
	img.img = mlx_new_image(so_long->mlx_ptr.mlx, g_x * 50, g_y * 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,\
	&img.endian);
    // get_image(so_long, 0, 0);
    check_image(so_long->map, so_long);
    mlx_key_hook(so_long->mlx_ptr.win, deal_key, (void *)so_long);
	mlx_loop(so_long->mlx_ptr.mlx);
}
