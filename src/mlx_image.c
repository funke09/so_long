/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:46:30 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/19 06:16:37 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_image(t_long *so_long, int x, int y)
{
	if (x >= g_x || y >= g_y)
		return ;
	if (so_long->map[y][x] == 'C')
		so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
		"images/coin.xpm", &so_long->x, &so_long->y);
	else if (so_long->map[y][x] == 'E')
		so_long->image = mlx_xpm_file_to_image(so_long->mlx_ptr.mlx, \
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
	while (y < g_y)
	{
		x = 0;
		while (x < g_x)
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
	while (i < g_y)
	{
		j = 0;
		while (j < g_x)
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	deal_key(int key, t_long *so_long)
{
	int	steps;

	steps = so_long->move;
	if (key == ESC)
	{
		ft_putstr_fd("\e[33m\e[1mGame closed! (ESC)\e[0m\n", 1);
		ft_exit(so_long);
	}
	else
		movements(key, so_long);
	if (steps != so_long->move)
		printf("Steps: %d\n", so_long->move);
	print_map(so_long);
	print_steps(so_long);
	return (0);
}

int	ft_expose(t_long *so_long)
{
	print_map(so_long);
	return (0);
}

void	my_mlx(t_long *so_long)
{
	so_long->mlx_ptr.mlx = mlx_init();
	so_long->mlx_ptr.win = mlx_new_window(so_long->mlx_ptr.mlx, \
	g_x * SIZE, g_y * SIZE, "so_long ");
	pos_player(so_long);
	count_collec(so_long);
	print_map(so_long);
	mlx_hook(so_long->mlx_ptr.win, X_EVENT_KEY_PRESS, \
	1L << 0, deal_key, so_long);
	mlx_hook(so_long->mlx_ptr.win, X_EVENT_KEY_EXIT, 1L << 0, ft_exit, so_long);
	mlx_expose_hook(so_long->mlx_ptr.win, ft_expose, so_long);
	mlx_loop(so_long->mlx_ptr.mlx);
}
