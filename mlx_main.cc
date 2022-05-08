#include "mlx.h"
#include <unistd.h>

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

int main()
{
    void *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "my_window");
    mlx_loop(mlx_ptr);
    return 0;
}
