/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:42:12 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/30 08:41:23 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i <= 4)
		showerror("error: missed filename.ber");
	if (filename[i - 1] != 'r' || filename[i - 2] != 'e' \
	|| filename[i - 3] != 'b' \
	|| filename[i - 4] != '.')
		showerror("error: invalid filename");
}

int	main(int ac, char **av)
{
	int		ret;
	t_long	so_long;

	if (ac != 2)
		showerror("error: usage ./so_long filename.ber");
	check_extension(av[1]);
	ret = read_check(av[1], &so_long);
	if (ret < 0)
		return (ret);
	so_long.move = 0;
	my_mlx(&so_long);
	return (0);
}
