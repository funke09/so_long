/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:52:00 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/22 20:02:14 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	convert_color(int color, int endian)
{
	char	color_channel[4];

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
	return (*((int *)color_channel));
}

int	ft_exit(t_long *so_long)
{
	mlx_destroy_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win);
	free_long(so_long);
	exit (0);
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
		print_steps_int(steps);
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
