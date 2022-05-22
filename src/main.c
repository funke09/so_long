/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:42:12 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/22 01:54:03 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i <= 4)
		return (-1);
	if (filename[i - 1] != 'r' || filename[i - 2] != 'e' \
	|| filename[i - 3] != 'b'
		|| filename[i - 4] != '.')
		showerror("error: usage filename.ber");
	return (0);
}

int	main(int ac, char **av)
{
	int		ret;
	t_long	so_long;

	if (ac != 2)
		showerror("error: usage ./so_long filename.");
	ret = read_check(av[1], &so_long);
	if (ret < 0)
		return (ret);
	so_long.move = 0;
	my_mlx(&so_long);
	return (0);
}
