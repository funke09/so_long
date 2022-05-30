/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 04:46:11 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/30 08:27:52 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	enemy_move_right(t_long *var)
{
	if (var->map[var->ny][var->nx + 1] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map[var->ny][var->nx] = '0';
	var->nx += 1;
	var->map[var->ny][var->nx] = 'N';
	var->count_enemy++;
	return (0);
}

int	enemy_move_down(t_long *var)
{
	if (var->map[var->ny + 1][var->nx] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map[var->ny][var->nx] = '0';
	var->ny += 1;
	var->map[var->ny][var->nx] = 'N';
	var->count_enemy++;
	return (0);
}

int	enemy_move_left(t_long *var)
{
	if (var->map[var->ny][var->nx - 1] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map[var->ny][var->nx] = '0';
	var->nx -= 1;
	var->map[var->ny][var->nx] = 'N';
	var->count_enemy++;
	return (0);
}

int	enemy_move_up(t_long *var)
{
	if (var->map[var->ny - 1][var->nx] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map[var->ny][var->nx] = '0';
	var->ny -= 1;
	var->map[var->ny][var->nx] = 'N';
	var->count_enemy++;
	return (0);
}

int	enemy_patrol(t_long *var)
{
	usleep(80000);
	get_enemy_position(var);
	if ((var->map[var->ny][var->nx + 1] == '0'
		|| var->map[var->ny][var->nx + 1] == 'P')
		&& var->count_enemy < g_x)
		enemy_move_right(var);
	else if ((var->map[var->ny + 1][var->nx] == '0'
		|| var->map[var->ny + 1][var->nx] == 'P')
		&& var->count_enemy < (g_x + g_y))
		enemy_move_down(var);
	else if ( (var->map[var->ny][var->nx - 1] == '0' || var->map[var->ny][var->nx - 1] == 'P'))
		enemy_move_left(var);
	else if ((var->map[var->ny - 1][var->nx] == '0'
		|| var->map[var->ny - 1][var->nx] == 'P') )
		enemy_move_up(var);
	else
		var->count_enemy = 0;
	print_map(var);
	print_steps(var);
	return (0);
}
