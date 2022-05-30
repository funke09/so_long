/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:53:42 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/30 08:19:02 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	move_left(t_long *var)
{
	if (var->map[var->py][var->px - 1] == 'N')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map[var->py][var->px] = '0';
	var->px -= 1;
	var->map[var->py][var->px] = 'P';
	var->img_sp = "images/sprite2.xpm";
	var->move++;
	return (0);
}

int	move_right(t_long *var)
{
	if (var->map[var->py][var->px + 1] == 'N')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map[var->py][var->px] = '0';
	var->px += 1;
	var->map[var->py][var->px] = 'P';
	var->img_sp = "images/sprite.xpm";
	var->move++;
	return (0);
}

int	move_down(t_long *var)
{
	if (var->map[var->py + 1][var->px] == 'N')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map[var->py][var->px] = '0';
	var->py += 1;
	var->map[var->py][var->px] = 'P';
	var->move++;
	return (0);
}

int	move_up(t_long *var)
{
	if (var->map[var->py - 1][var->px] == 'N')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map[var->py][var->px] = '0';
	var->py -= 1;
	var->map[var->py][var->px] = 'P';
	var->move++;
	return (0);
}

int	movements(int key, t_long *var)
{
	if ((key == A_KEY || key == LEFT_KEY)
		&& (var->map[var->py][var->px - 1] == 'E'))
		check_collect(var);
	else if ((key == A_KEY || key == LEFT_KEY)
		&& (var->map[var->py][var->px - 1] != '1'))
		move_left(var);
	if ((key == D_KEY || key == RIGHT_KEY)
		&& (var->map[var->py][var->px + 1] == 'E'))
		check_collect(var);
	else if ((key == D_KEY || key == RIGHT_KEY)
		&& (var->map[var->py][var->px + 1] != '1'))
		move_right(var);
	if ((key == S_KEY || key == DOWN_KEY)
		&& (var->map[var->py + 1][var->px] == 'E'))
		check_collect(var);
	else if ((key == S_KEY || key == DOWN_KEY)
		&& (var->map[var->py + 1][var->px] != '1'))
		move_down(var);
	if ((key == W_KEY || key == UP_KEY)
		&& (var->map[var->py - 1][var->px] == 'E'))
		check_collect(var);
	else if ((key == W_KEY || key == UP_KEY)
		&& (var->map[var->py - 1][var->px] != '1'))
		move_up(var);
	return (0);
}
