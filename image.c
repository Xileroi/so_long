/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:03:41 by ylounici          #+#    #+#             */
/*   Updated: 2023/04/29 01:51:06 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	colle_image_wall(t_game *all)
{
	mlx_put_image_to_window(all->mlx, all->win, all->img.wall, all->var.d_x,
		all->var.d_y);
	all->var.d_x += TILE;
	all->var.j++;
}

void	colle_image_coin(t_game *all)
{
	mlx_put_image_to_window(all->mlx, all->win, all->img.coin, all->var.d_x,
		all->var.d_y);
	all->var.d_x += TILE;
	all->var.j++;
}

void	colle_image_player(t_game *all)
{
	mlx_put_image_to_window(all->mlx, all->win, all->img.player,
		all->var.d_x, all->var.d_y);
	all->var.d_x += TILE;
	all->var.j++;
}

void	colle_image_exit(t_game *all)
{	
	mlx_put_image_to_window(all->mlx, all->win, all->img.exit, all->var.d_x,
		all->var.d_y);
	all->var.d_x += TILE;
	all->var.j++;
}
