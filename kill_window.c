/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:05:04 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/18 15:16:47 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *all)
{
	int	i;

	i = 0;
	while (all->map.map[i])
		free(all->map.map[i++]);
	free(all->map.map[i]);
}


int	kill_window(t_game *all)
{
	free_map(all);
	exit(0);
}
