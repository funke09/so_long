/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:00:40 by zcherrad          #+#    #+#             */
/*   Updated: 2022/06/04 23:48:55 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	count_lines(char *filename, t_long *so)
{
	int		count;
	char	*line;

	count = 0;
	so->g_fd = open(filename, O_RDONLY);
	line = NULL;
	if (so->g_fd < 0)
		return (-1);
	line = get_next_line(so->g_fd);
	while (line || count > 0)
	{
		if (count > 0)
			line = get_next_line(so->g_fd);
		if (line == NULL)
			break ;
		free(line);
		line = NULL;
		count++;
	}
	return (count);
}

int	read_first(char *filename, t_long *so_long, char **line, int *len)
{
	so_long->g_y = count_lines(filename, so_long);
	so_long->map = (char **)malloc(sizeof(char *) * (so_long->g_y + 1));
	if (!so_long->map)
		return (-1);
	*(line) = NULL;
	so_long->g_fd = open(filename, O_RDONLY);
	if (so_long->g_fd < 0)
		return (-1);
	*(line) = get_next_line(so_long->g_fd);
	if (!*(line) || !full_wall(*(line)))
		showerror("Invalid map: top wall not configured");
	*len = ft_strlen(*(line));
	so_long->map[0] = ft_strndup(*(line), (*len) - 1);
	free(*(line));
	line = NULL;
	return (1);
}

int	read_last(int *i, t_long *so_long, int *len)
{
	if (!full_wall(so_long->map[*i - 1]))
		showerror("Invalid map: down wall not configured");
	if (so_long->g_symbol[POS] != 1 || so_long->g_symbol[COLL] < 1 || so_long->g_symbol[EXT] < 1)
		showerror("Invalid map: invalid symbols");
	so_long->g_x = (*len) - 1;
	return (1);
}

int	check_if_last_line(char *line, t_long *so_long, int *i, int *len)
{
	int	l;

	l = ft_strlen(line);
	if (line[l - 1] != '\n')
	{
		if (l + 1 != *len)
			return (-7);
		so_long->map[(*i)++] = ft_strndup(line, l);
		free(line);
		return (1);
	}
	return (0);
}

int	read_check(char *filename, t_long *so_long)
{
	int		i;
	char	*line;
	int		len;

	i = 1;
	len = 0;
	if ((read_first(filename, so_long, &line, &len)) < 0)
		return (-1);
	line = get_next_line(so_long->g_fd);
	while (line || i > 1)
	{
		if (i > 1)
			line = get_next_line(so_long->g_fd);
		if (line && check_if_last_line(line, so_long, &i, &len) > 0)
			break ;
		mini_check(&line, len, so_long);
		so_long->map[i++] = ft_strndup(line, len - 1);
		ft_strdel(&line);
	}
	so_long->map[i] = 0;
	read_check2(so_long, i, len);
	return (1);
}
