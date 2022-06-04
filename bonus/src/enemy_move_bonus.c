/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 04:45:29 by zcherrad          #+#    #+#             */
/*   Updated: 2022/06/04 23:45:46 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_enemy_position(t_long *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->g_y)
	{
		col = 0;
		while (col < var->g_x)
		{
			if (var->map[row][col] == 'N')
			{
				var->nx = col;
				var->ny = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	step_into_enemy(int key, t_long *var)
{
	if ((key == A_KEY)
		&& (var->map[var->py][var->px - 1] == 'N'))
	{
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	}
	if ((key == D_KEY)
		&& (var->map[var->py][var->px + 1] == 'N'))
	{
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	}
	if ((key == S_KEY)
		&& (var->map[var->py + 1][var->px] == 'N'))
	{
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	}
	if ((key == W_KEY)
		&& (var->map[var->py - 1][var->px] == 'N'))
	{
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	}
	return (0);
}
