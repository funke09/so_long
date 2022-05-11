#include <mlx.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int 	deal_key(int key, void *arg)
{
	ft_putchar('z');
	//mlx_pixel_put(mlx_ptr, win_ptr);
	return(0);
}

int convert_color(int color, int endian)
{    
    char color_channel[4];

    if (endian == 1) 
    {
        color_channel[0] = (color >> 24);
        color_channel[1] = (color >> 16) & 0xFF;
        color_channel[2] = (color >> 8) & 0xFF;
        color_channel[3] = (color) & 0xFF;
    }
    else if (endian == 0)   
    {
        color_channel[0] = (color) & 0xFF;
        color_channel[1] = (color >> 8) & 0xFF;
        color_channel[2] = (color >> 16) & 0xFF;
        color_channel[3] = (color >> 24);
    }
    return *((int*)color_channel);
}

int main()
{
    void *mlx_ptr;
    void    *win_ptr;
	void	*image;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "my_window");
	image = mlx_new_image(mlx_ptr, 500, 500);

    int pixel_bites;
    int line_bites;
    int endian;
    int *buffer = (int *)mlx_get_data_addr(image, &pixel_bites, &line_bites, &endian);
    int color = 0xABCDEF;
    
    if (pixel_bites != 32)
        color = mlx_get_color_value(mlx_ptr, color);
    for(int y = 0; y < 500; ++y)
    {
        for(int x = 0; x < 500; ++x)
        {
            
            int pixel = (y * 500) + x;
            buffer[pixel + 0] = convert_color(0xff0000, endian);
            // printf("%d\n", );

        }
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
    mlx_loop(mlx_ptr);
    return(0);
}

    // for(int y = 0; y < 500; ++y)
    //     for(int x = 0; x < 500; ++x)
    //     {
    //         int pixel = (y * line_bites) + x;
    //         buffer[pixel] = 0xff0000;
    //     }