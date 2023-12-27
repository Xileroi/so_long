/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapable.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:00 by yalounic          #+#    #+#             */
/*   Updated: 2023/12/27 15:20:10 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_limit(char **str)
{
	int	i;
	int	j;
	int	max_j;

	i = 0;
	j = 0;
	while (str[i][j])
	{
		i++;
		if (str[i][j] == 10)
		{
			max_j = j;
			j++;
			i = 0;
		}
	}
	return (max_j);
}

void	ft_run9(char **str, int i, int j, int max_i)
{
	int	i;

	i = 0;
	if (str[i + 1][j] != '1' && str[i + 1][j] != '9')
	{
		i++;
		str[i + 1][j] = '9';
	}
	if (str[i - 1][j] != '1' && str[i - 1][j] != '9')
	{
		i++;
		str[i - 1][j] = '9';
	}
	if (str[i][j + 1] != '1' && str[i][j + 1] != '9')
	{
		i++;
		str[i][j + 1] = '9';
	}
	if (str[i][j - 1] != '1' && str[i][j - 1] != '9')
	{
		i++;
		str[i][j - 1] = '9';
	}
	return (i);
}

int	ft_parse_map(char **str, t_game *all)
{
	int	i;
	int	j;
	//int	max_i;

	i = 0;
	j = 0;
	write(1, "o", 1);
	while (str[i][j] != 'P')
	{
		i++;
		write(1, "o", 1);
		if (str[i][j] == 10)
		{
			j++;
			//max_i = i;
			i = 0;
		}
	}
	str[i][j] = '9';
	//ft_run9(str, i, j, max_i);
	if (all->cep.player == 1)
		return (0);
	else
		return (1);
}

/*#include "so_long.h"

void	ft_fplayer(char **str, t_game *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < all->map.height)
	{
		while (str[y][x])
		{
			if (str[y][x] == 'P')
			{
				all->x = x + 1;
				all->y = y + 1;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

/*int	replace_space(int x, int y, char **str)
{
	int	i;

	i = 0;
	if (str[y + 1][x] != '1' && str[y + 1][x] != '9')
	{
		i++;
		str[y + 1][x] = '9';
	}
	if (str[y - 1][x] != '1' && str[y - 1][x] != '9')
	{
		i++;
		str[y - 1][x] = '9';
	}
	if (str[y][x + 1] != '1' && str[y][x + 1] != '9')
	{
		i++;
		str[y][x + 1] = '9';
	}
	if (str[y][x - 1] != '1' && str[y][x - 1] != '9')
	{
		i++;
		str[y][x - 1] = '9';
	}
	return (i);
}*/

/*int	ft_adieux_temp(t_game *all, char **str)
{
	int	y;

	y = 0;
	while (y < all->map.height)
	{
		free(str[y]);
		y++;
	}
	free(str);
	return (0);
}*/

/*int	verif_map_temp(t_game *all, char **str)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < all->map.height - 1)
	{
		if (str[y][x] == 'C' || str[y][x] == 'E'
			|| str[y][x] == 'P')
		{
			printf("Error\nMap non faisable");
			ft_adieux_temp(all, str);
			finito(1);
			return (0);
		}
		x++;
		if (x >= all->map.lenght - 1)
		{
			y++;
			x = 1;
		}
	}
	ft_adieux_temp(all, str);
	return (1);
}*/

int	map_is_good(t_game *all, char **str)
{
	int	x;
	int	y;

	str[all->y - 1][all->x - 1] = '9';
	x = 1;
	y = 1;
	write(1, "Oui", 3);
	while (y < all->map.height - 1)
	{
		if (str[y][x] == '9')
		{
			if (replace_space(x, y, str) != 0)
			{
				x = 0;
				y = 1;
			}
		}
		x++;
		if (x >= all->map.lenght - 1)
		{
			y++;
			x = 1;
		}
	}
	return (verif_map_temp(all, str));
}*/
