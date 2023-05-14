/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:04:13 by ylounici          #+#    #+#             */
/*   Updated: 2023/04/29 01:53:56 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	colle_image_ground(t_game *all)
{
	mlx_put_image_to_window(all->mlx, all->win, all->img.ground, all->var.d_x,
		all->var.d_y);
	all->var.d_x += TILE;
	all->var.j++;
}

void	wasd(t_game *all)
{
	all->pos.p_player.x = all->var.i;
	all->pos.p_player.y = all->var.j;
	colle_image_player(all);
}

void	ft_graphic(t_game *all)
{
	ini_variable(all);
	while (all->map.map[all->var.i] != NULL)
	{
		if (all->map.map[all->var.i][all->var.j] == 'C')
			colle_image_coin(all);
		else if (all->map.map[all->var.i][all->var.j] == 'E')
			colle_image_exit(all);
		else if (all->map.map[all->var.i][all->var.j] == 'P')
			wasd(all);
		else if (all->map.map[all->var.i][all->var.j] == '\0')
			backslash_n(all);
		else if (all->map.map[all->var.i][all->var.j] == '1')
			colle_image_wall(all);
		else if (all->map.map[all->var.i][all->var.j] == '0')
			colle_image_ground(all);
		else
		{	
			all->var.d_x += TILE;
			all->var.j++;
		}
	}
}

int	ft_refresh(t_game *all)
{	
	ft_graphic(all);
	if (ft_check_wall(all, all->pos.p_player.y, all->pos.p_player.x) == 1)
		put_steps(all);
	return (1);
}
