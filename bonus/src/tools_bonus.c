/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:14:37 by zcherrad          #+#    #+#             */
/*   Updated: 2022/06/04 23:44:15 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	full_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			continue ;
		}
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P' \
	|| c == '\n' || c == 'N')
		return (1);
	return (0);
}

void	fill_symbol(char c, t_long *so_long)
{
	if (c == 'P')
		so_long->g_symbol[POS] += 1;
	else if (c == 'C')
		so_long->g_symbol[COLL] += 1;
	else if (c == 'E')
		so_long->g_symbol[EXT] += 1;
	else if (c == 'N')
		so_long->g_symbol[ENM] += 1;
}

int	check_line(char *line, t_long *so)
{
	int	i;

	i = 1;
	if (line[0] != '1')
		showerror("Invalid map: top wall not configured");
	while (line[i])
	{
		if (!is_valid(line[i]))
			showerror("Invalid map: invalid symbols");
		else if (line[i] == 'P' || line[i] == 'C' || \
		line[i] == 'E' || line[i] == 'N')
			fill_symbol(line[i], so);
		i++;
	}
	if (line[i - 2] != '1')
		showerror("Invalid map: wall not configured");
	return (1);
}

int	count_collec(t_long *var)
{
	int		row;
	int		col;

	row = 0;
	var->collect = 0;
	while (row < var->g_y)
	{
		col = 0;
		while (col < var->g_x)
		{
			if (var->map[row][col] == 'C')
				var->collect += 1;
			col++;
		}
		row++;
	}
	return (var->collect);
}
