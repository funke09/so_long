#include "../so_long.h"


void    get_image(t_long *so_long)
{
    so_long->coins_img = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
    "images/coin.xpm", &so_long->x, &so_long->y);
    if(so_long->coins_img == '\0')
      showerror((void*)&so_long, "no coins");
    so_long->door_img = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx,\
    "images/close_door.xpm", &so_long->x, &so_long->y);
    if(so_long->door_img == '\0')
        showerror((void*)&so_long, "no exit");
    so_long->player_img = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
    "images/princess.xpm", &so_long->x, &so_long->y);
    if(so_long->player_img == '\0')
         showerror((void*)&so_long, "no player");
    so_long->wall_img = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
    "images/wall.xpm", &so_long->x, &so_long->y);
    if(so_long->wall_img == '\0')
        showerror((void*)&so_long, "no walls");
    so_long->empty = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
    "images/space.xpm", &so_long->x, &so_long->y);
    if(so_long->empty == '\0')
         showerror((void*)&so_long, "no spaces");

     return;    

}

void    check_image(char **map, t_long *so_long)
{
    // int x = 0;
    // int y 0;
    so_long->y = 0;
    while(map[so_long->y])
    {
        so_long->x = 0;
        while (map[so_long->y][so_long->x])
        {
            if (map[so_long->y][so_long->x] == '0')
                mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win,\
                so_long->empty, so_long->x * 50, so_long->y * 50);
            if (map[so_long->y][so_long->x] == '1')
				mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
				so_long->wall_img, so_long->x * 50, so_long->y * 50);
             if (map[so_long->y][so_long->x] == 'P')
				mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
				so_long->player_img, so_long->x * 50, so_long->y * 50);
             if (map[so_long->y][so_long->x] == 'C')
				mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
				so_long->coins_img, so_long->x * 50, so_long->y * 50);
             if (map[so_long->y][so_long->x] == 'E')
				mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
				so_long->door_img, so_long->x * 50, so_long->y * 50);
            so_long->x++;
        }
       so_long->y++; 
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
    // (void)(arg);
    // int fd;
    (void) key;
	// ft_putchar_fd('z', 1);
    printf("%d\n", key);
    // if(key == ESC)
    //    ft_exit(so_long);
    if(key == W_KEY) // up 
    {
        printf("w");
    }
    else if(key == S_KEY) // down
    {
        printf("w");
    }
    else if(key == A_KEY) // left
    {
        printf("w");
    }
    else if(key == D_KEY) // right
    {
        printf("w");
    }
    check_image(so_long->map, so_long);
	return 0;
}

void    my_mlx(t_long *so_long)
{
    t_data img;
    // int pixel_bites;
    // int line_bites;
    // int endian;

    so_long->mlx_ptr.mlx = mlx_init();
	so_long->mlx_ptr.win = mlx_new_window(so_long->mlx_ptr.mlx, g_x * 50, g_y * 50, "Hello world!");
	img.img = mlx_new_image(so_long->mlx_ptr.mlx, g_x * 50, g_y * 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    get_image(so_long);
    check_image(so_long->map, so_long);
    mlx_key_hook(so_long->mlx_ptr.win, deal_key, (void *)so_long);
    //mlx_hook(so_long->win_ptr, 2, 1L<<0, deal_key, &so_long);
	mlx_loop(so_long->mlx_ptr.mlx);
}