/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ini_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:04:27 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/20 12:12:05 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ini_sprites(t_game *all)
{
	all->img.ground = mlx_xpm_file_to_image(all->mlx,
			"./sprites/ground.xpm", &all->map.lenght, &all->map.height);
	all->img.wall = mlx_xpm_file_to_image(all->mlx,
			"./sprites/wall.xpm", &all->map.lenght, &all->map.height);
	all->img.exit = mlx_xpm_file_to_image(all->mlx,
			"./sprites/exit.xpm", &all->map.lenght, &all->map.height);
	all->img.coin = mlx_xpm_file_to_image(all->mlx,
			"./sprites/coin.xpm", &all->map.lenght, &all->map.height);
	all->img.player = mlx_xpm_file_to_image(all->mlx,
			"./sprites/player.xpm", &all->map.lenght, &all->map.height);
}

void	ini_variable(t_game *all)
{
	all->var.i = 0;
	all->var.j = 0;
	all->var.v_i = 0;
	all->var.v_j = 0;
	all->var.d_x = 0;
	all->var.d_y = 0;
}

void	backslash_n(t_game *all)
{
	all->var.d_y += TILE;
	all->var.i++;
	all->var.d_x = 0;
	all->var.j = 0;
	all->end_game = 0;
}

void	ini_mlx(t_game *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->map.lenght * TILE,
			all->map.height * TILE, "so_long");
}
