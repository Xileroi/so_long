/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapable.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:00 by yalounic          #+#    #+#             */
/*   Updated: 2024/01/20 12:23:46 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif(char **map, int i, int j, int c)
{
	int	e;

	e = 0;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c = 1;
			if (map[i][j] == 'E')
				e = 1;
			j++;
		}
		i++;
	}
	if (c == 1 || e == 1)
		finito(i);
	return (1);
}

int	ft_run9(char **map, int i, int j)
{
	if (i < 0 || j < 0 || !map[i] || !map[i][j] || map[i][j] == '9')
		return (0);
	if (map[i][j] == '0' || map[i][j] == 'C'
		|| map[i][j] == 'E' || map[i][j] == 'P')
	{
		if (map[i][j] == 'E')
		{
			map[i][j] = '1';
			return (0);
		}
		else
			map[i][j] = '9';
		ft_run9(map, i + 1, j);
		ft_run9(map, i - 1, j);
		ft_run9(map, i, j + 1);
		ft_run9(map, i, j - 1);
	}
	return (0);
}

int	ft_parse_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] && map[i][j] != 'P')
	{
		if (map[i][j] == '\0')
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	if (map[i][j] == 'P')
	{
		ft_run9(map, i, j);
		ft_verif(map, i, j, 0);
	}
	else
		return (0);
	return (1);
}
