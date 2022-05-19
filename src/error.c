/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 05:45:46 by zcherrad          #+#    #+#             */
/*   Updated: 2022/05/19 05:46:22 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	showerror(t_long *so_long, char *message)
{
	(void)so_long;
	ft_putendl_fd(message, STDERR_FILENO);
	exit(1);
}
