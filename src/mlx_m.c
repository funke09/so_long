/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:52:00 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/19 05:53:08 by zcherrad         ###   ########.fr       */
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
