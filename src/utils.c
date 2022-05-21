/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:02:51 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/21 01:12:16 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
