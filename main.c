/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:35:27 by ylounici          #+#    #+#             */
/*   Updated: 2023/10/20 13:07:47 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	finito(int i)
{
	(void) i;
	ft_printf("Error\nTu es finito.\n");
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
	int			fd;
	t_game		all;

	if (argc != 2)
	{
		printf("Error\nTrop ou pas assez d'arguments\n");
		return (0);
	}
	ft_check_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (ini_so_long(fd, &all) < 0)
		return (0);
	all.steps = 0;
	all.key = -1;
	printf("Nombre de pas : %d\n", all.steps);
	mlx_key_hook(all.win, deplacement, (void *)&all);
	mlx_hook(all.win, 17, 0, kill_window, (void *)&all);
	mlx_loop_hook(all.mlx, ft_refresh, &all);
	mlx_loop(all.mlx);
	close(fd);
}
