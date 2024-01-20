/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:05:57 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/20 12:21:45 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_player(t_game *all)
{
	ft_printf("Tu as fini en %d pas ! Essai de faire mieux.\n", all->steps);
	all->map.map[all->pos.p_player.x][all->pos.p_player.y] = '0';
	ft_graphic(all);
	exit(0);
}

void	put_steps(t_game *all)
{
	char	*str;

	str = ft_itoa(all->steps);
	mlx_string_put(all->mlx, all->win, 32, 32, 0x9400D3, str);
	free(str);
}

int	ft_check_wall(t_game *all, int col, int line)
{
	if (all->map.map[line][col] == '1')
		return (0);
	if (all->map.map[line][col] == 'E' && all->cep.coins == 0)
		all->end_game = 1;
	if (all->map.map[line][col] == 'E')
		return (0);
	return (1);
}

void	ft_update(int col, int line, t_game *all)
{
	int	x;
	int	y;
	int	valid;

	x = all->pos.p_player.x;
	y = all->pos.p_player.y;
	valid = ft_check_wall(all, col, line);
	if (all->end_game == 1)
		kill_player(all);
	if (valid == 1)
	{
		if (all->map.map[line][col] == 'C')
		{
			all->cep.coins--;
			if (all->cep.coins != 0)
				ft_printf("Il reste %d coffres a trouver !\n", all->cep.coins);
			if (all->cep.coins == 0)
				ft_printf("Tu as tous les coffres, prends vite la sortie !\n");
		}
		all->map.map[x][y] = '0';
		all->map.map[line][col] = 'P';
		all->pos.p_player.x = line;
		all->pos.p_player.y = col;
	}
}

int	deplacement(int keycode, t_game *all)
{
	int	col;
	int	line;

	col = all->pos.p_player.y;
	line = all->pos.p_player.x;
	if (keycode == UP)
		line--;
	if (keycode == DOWN)
		line++;
	if (keycode == LEFT)
		col--;
	if (keycode == RIGHT)
		col++;
	if (keycode == ESC)
		kill_window(all);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
	{
		all->steps++;
		ft_printf("Nombre de pas : %d\n", all->steps);
		ft_update(col, line, all);
	}
	return (1);
}
