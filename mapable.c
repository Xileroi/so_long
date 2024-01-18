/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapable.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:00 by yalounic          #+#    #+#             */
/*   Updated: 2024/01/18 17:02:17 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif(char **map, int i, int j)
{
	int	c;
	int	p;
	int	e;

	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c = 1;
			if (map[i][j] == 'E')
				e = 1;
			if (map[i][j] == 'P')
				p = 1;
			j++;
		}
		i++;
	}
	if (c == 1 || e == 1 || p == 1)
		finito(i);
	return (1);
}

int ft_run9(char **map, int i, int j)
{
    if (i < 0 || j < 0 || !map[i] || !map[i][j] || map[i][j] == '9')
        return (0);
    if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E')
    {
		if (map[i][j] == 'E')
			map[i][j] = '1';
		else
        	map[i][j] = '9';
        ft_run9(map, i + 1, j);
        ft_run9(map, i - 1, j);
        ft_run9(map, i, j + 1);
        ft_run9(map, i, j - 1);
    }
    return (0);
}

/*int	ft_run9(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E')
		map[i][j] = '9';
	if (map[i + 1] && (map[i + 1][j] == '0'
		|| map[i + 1][j] == 'C' || map[i + 1][j] == 'E'))
	{
		i++;
		ft_run9(map, i, j);
	}
	if (i - 1 >= 0 && (map[i - 1][j] == '0'
		|| map[i - 1][j] == 'C' || map[i - 1][j] == 'E'))
	{
		i--;
		ft_run9(map, i, j);
	}
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'E')
	{
		j++;
		ft_run9(map, i, j);
	}
	if (j - 1 >= 0 && (map[i][j - 1] == '0'
		|| map[i][j - 1] == 'C' || map[i][j - 1] == 'E'))
	{
		j--;
		ft_run9(map, i, j);
	}
	return (0);
}*/

int	ft_parse_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] && map[i][j] != 'P')
	{
		if (map[i][j] == '\0' || map[i][j] == 10)
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	if (map[i] && map[i][j] == 'P')
	{
		map[i][j] = '9';
		ft_run9(map, i, j);
		ft_verif(map, 0, 0);
	}
	else
		return (0);
	return (1);
}
