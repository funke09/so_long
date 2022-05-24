/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:02:51 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/24 03:36:18 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_collect(t_long *var)
{
	if (count_collec(var) == 0)
	{
		ft_putstr_fd("\e[34m\e[1mCONGRATS\n!!!! You WON !!!!\e[0m\n", 1);
		ft_exit(var);
	}
	return (0);
}

void	free_long(t_long *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[i])
	{
		free(so_long->map[i]);
		so_long->map[i] = NULL;
		i++;
	}
	free(so_long->map);
	so_long->map = NULL;
}

int	print_steps(t_long *var)
{
	char	*str;

	str = ft_itoa(var->move);
	mlx_string_put(var->mlx_ptr.mlx, var->mlx_ptr.win, (SIZE) + 5,
		15, 0xfffffff, str);
	free(str);
	return (0);
}

int	read_check2(t_long *so_long, int i, int len)
{
	if ((read_last(&i, so_long, &len)) < 0)
		return (-2);
	close(g_fd);
	return (1);
}

void	mini_check(char **line, int len)
{
	if (len != (int)ft_strlen(*line))
	{
		ft_strdel(line);
		showerror("Invalid map: not a retangle");
	}
	if (!check_line(*line))
	{
		ft_strdel(line);
		showerror("Error: Invalid map");
	}
}
