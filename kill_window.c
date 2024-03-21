/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:05:04 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/28 16:19:32 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *all)
{
	int	i;

	i = 0;
	while (all->map.map && all->map.map[i])
	{
		free(all->map.map[i]);
		i++;
	}
	if (all->map.map)
		free(all->map.map);
}

void	free_mapi(char **mapi)
{
	int	i;

	i = 0;
	while (mapi[i])
		free(mapi[i++]);
	free(mapi[i]);
	free(mapi);
}

int	kill_windowi(t_game *all)
{
	close(all->fd);
	exit(0);
}

int	kill_window(t_game *all)
{
	free_map(all);
	ft_destroy_image(all);
	mlx_destroy_window(all->mlx, all->win);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
	close(all->fd);
	exit(0);
}
