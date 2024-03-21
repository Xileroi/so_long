/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:35:27 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/28 16:48:39 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	finito(t_game *all)
{
	ft_printf("Error\nIl y a une erreur de map ou de mémoire.\n");
	free_map(all);
	kill_windowi(all);
	exit (0);
}

int	finitovoid(t_game *all)
{
	ft_printf("Error\nIl y a une erreur de map ou de mémoire.\n");
	close(all->fd);
	exit (0);
}

int	finitoi(t_game *all, char *str)
{
	ft_printf("Error\nIl y a une erreur de map ou de mémoire.\n");
	free(str);
	kill_windowi(all);
	exit (0);
}

int	ini_so_long(int fd, t_game *all)
{
	map_read(fd, all);
	ini_mlx(all);
	ft_ini_sprites(all);
	ft_graphic(all);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game		all;

	if (argc != 2)
	{
		ft_printf("Error\nTrop ou pas assez d'arguments\n");
		return (0);
	}
	ft_check_name(argv[1], &all);
	all.fd = open(argv[1], O_RDONLY);
	if (ini_so_long(all.fd, &all) < 0)
		return (0);
	all.steps = 0;
	all.key = -1;
	ft_printf("Nombre de pas : %d\n", all.steps);
	mlx_key_hook(all.win, deplacement, (void *)&all);
	mlx_hook(all.win, 17, 0, kill_window, (void *)&all);
	mlx_loop_hook(all.mlx, ft_refresh, &all);
	mlx_loop(all.mlx);
	ft_destroy_image(&all);
	free(all.mlx);
	free(all.win);
	close(all.fd);
	return (1);
}
