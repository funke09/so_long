/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:02:51 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/22 23:41:31 by zcherrad         ###   ########.fr       */
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

int	read_check2(t_long *so_long, int i, int len)
{
	if ((read_last(&i, so_long, &len)) < 0)
		return (-2);
	close(g_fd);
	return (1);
}

// int	loop_check(t_long *so_long, char **filename)
// {
// 	int		i;
// 	char	*line;
// 	int		len;

// 	i = 1;
// 	len = 0;
// 	if ((read_first(filename, so_long, &line, &len)) < 0)
// 		return (-1);
// 	line = get_next_line(g_fd);
// 	while (line || i > 1)
// 	{
// 		if (i > 1)
// 			line = get_next_line(g_fd);
// 		if (line && check_if_last_line(line, so_long, &i, &len) > 0)
// 			break ;
// 		if (len != (int)ft_strlen(line) || !check_line(line))
// 		{
// 			ft_strdel(&line);
// 			showerror("Invalid map: lateral wall not configured \
// 			or not a retangle");
// 		}
// 		so_long->map[i++] = ft_strndup(line, len - 1);
// 		ft_strdel(&line);
// 		return (1);
// 	}
// }
