/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:46:30 by zcherrad          #+#    #+#             */
/*   Updated: 2022/06/05 00:26:46 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_image(t_long *so_long, int x, int y)
{
	if (x >= so_long->g_x || y >= so_long->g_y)
		return ;
	if (so_long->map[y][x] == 'C')
		so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
		"images/coin.xpm", &so_long->x, &so_long->y);
	else if (so_long->map[y][x] == 'E')
		so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
		"images/exit.xpm", &so_long->x, &so_long->y);
	else if (so_long->map[y][x] == 'P')
		so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
		"images/player.xpm", &so_long->x, &so_long->y);
	else if (so_long->map[y][x] == '1')
		so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
		"images/tree.xpm", &so_long->x, &so_long->y);
	else if (so_long->map[y][x] == '0')
		so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
		"images/space.xpm", &so_long->x, &so_long->y);
	if (!so_long->image)
		showerror("error missed .xpm file.");
	mlx_put_image_to_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win, \
	so_long->image, x * SIZE, y * SIZE);
	mlx_destroy_image(so_long->mlx_ptr.mlx, so_long->image);
	so_long->image = NULL;
}

void	print_map(t_long *so_long)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < so_long->g_y)
	{
		x = 0;
		while (x < so_long->g_x)
		{
			load_image(so_long, x, y);
			x++;
		}
		y++;
	}
}

void	pos_player(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->g_y)
	{
		j = 0;
		while (j < so_long->g_x)
		{
			if (so_long->map[i][j] == 'P')
			{
				so_long->px = j;
				so_long->py = i;
			}
			j++;
		}
		i++;
	}
}

void	print_steps_int(int steps)
{
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(steps, 1);
	ft_putchar_fd('\n', 1);
}
