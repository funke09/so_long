/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:45:46 by zcherrad          #+#    #+#             */
/*   Updated: 2022/06/04 01:48:26 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	showerror(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	free_exit(t_long *var, char *msg)
{
	printf("%s", msg);
	free_long(var);
	exit(0);
}

int	count_enemy(t_long *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < so_long->g_y)
	{
		col = 0;
		while (col < so_long->g_x)
		{
			if (var->map[row][col] == 'N')
				var->count_enemy += 1;
			col++;
		}
		row++;
	}
	return (var->count_enemy);
}
