/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_m_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:52:00 by zcherrad          #+#    #+#             */
/*   Updated: 2022/06/04 23:50:00 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_exit(t_long *so_long)
{
	ft_putstr_fd("\e[33m\e[1mGame closed!\e[0m\n", 1);
	mlx_destroy_window(so_long->mlx_ptr.mlx, so_long->mlx_ptr.win);
	free_long(so_long);
	exit (0);
}

int	deal_key(int key, t_long *so_long)
{
	int	steps;

	steps = so_long->move;
	if (key == ESC)
		ft_exit(so_long);
	else
	{
		if (so_long->enemy > 0)
			step_into_enemy(key, so_long);
		movements(key, so_long);
	}
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
	so_long->g_x * SIZE, so_long->g_y * SIZE, "so_long_bonus");
	pos_player(so_long);
	count_collec(so_long);
	count_enemy(so_long);
	print_map(so_long);
	mlx_hook(so_long->mlx_ptr.win, X_EVENT_KEY_PRESS, \
	1L << 0, deal_key, so_long);
	mlx_hook(so_long->mlx_ptr.win, X_EVENT_KEY_EXIT, 1L << 0, ft_exit, so_long);
	mlx_expose_hook(so_long->mlx_ptr.win, ft_expose, so_long);
	if (so_long->count_enemy > 0)
		mlx_loop_hook(so_long->mlx_ptr.mlx, enemy_patrol, so_long);
	mlx_loop(so_long->mlx_ptr.mlx);
}
