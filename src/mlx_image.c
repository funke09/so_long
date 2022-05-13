#include "../so_long.h"


void    get_image(t_long *so_long)
{
    so_long->coins_img = mlx_xpm_file_to_image(so_long->mlx_ptr, \
    "images/coin.xpm", &so_long->x, &so_long->y);
    if(so_long->coins_img == '\0')
      showerror((void*)&so_long, "no coins");
    so_long->door_img = mlx_xpm_file_to_image(so_long->mlx_ptr,\
    "images/door.xpm", &so_long->x, &so_long->y);
    if(so_long->door_img == '\0')
        showerror((void*)&so_long, "no exit");
    so_long->player_img = mlx_xpm_file_to_image(so_long->mlx_ptr, \
    "images/princess.xpm", &so_long->x, &so_long->y);
    if(so_long->player_img == '\0')
         showerror((void*)&so_long, "no player");
    so_long->wall_img = mlx_xpm_file_to_image(so_long->mlx_ptr, \
    "images/wall.xpm", &so_long->x, &so_long->y);
    if(so_long->wall_img == '\0')
        showerror((void*)&so_long, "no walls");
    so_long->empty = mlx_xpm_file_to_image(so_long->mlx_ptr, \
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
            mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,\
             so_long->empty, so_long->x * 50, so_long->y * 50);
            if (map[so_long->y][so_long->x] == '1')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, \
				so_long->wall_img, so_long->x * 50, so_long->y * 50);
             if (map[so_long->y][so_long->x] == 'P')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, \
				so_long->player_img, so_long->x * 50, so_long->y * 50);
             if (map[so_long->y][so_long->x] == 'C')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, \
				so_long->coins_img, so_long->x * 50, so_long->y * 50);
             if (map[so_long->y][so_long->x] == 'E')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, \
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
                so_long->x = i;
                so_long->y = j;
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

void    my_mlx(t_long *so_long)
{
    t_data img;
    // int pixel_bites;
    // int line_bites;
    // int endian;

    so_long->mlx_ptr = mlx_init();
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, g_x * 50, g_y * 50, "Hello world!");
	img.img = mlx_new_image(so_long->mlx_ptr, g_x * 50, g_y * 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, img.img, 0, 0);
    get_image(so_long);
    check_image(so_long->map, so_long);
	mlx_loop(so_long->mlx_ptr);
    // int pixel_bites;
    // int line_bites;
    // int endian;
    // int *buffer = (int *)mlx_get_data_addr(img.img, &pixel_bites, &line_bites, &endian);
    // int color = 0xABCDEF;
    
    // if (pixel_bites != 32)
    //     color = mlx_get_color_value(so_long->mlx_ptr, color);
    // for(int y = 0; y < 500; ++y)
    // {
    //     for(int x = 0; x < 500; ++x)
    //     {
            
    //         int pixel = (y * 500) + x;
    //         buffer[pixel] = convert_color(0xff0000, endian);
    //         // printf("%d\n", );

    //     }
    // }
    // mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->image, 0, 0);

}