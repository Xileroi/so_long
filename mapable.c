/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapable.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:00 by yalounic          #+#    #+#             */
/*   Updated: 2024/01/17 23:51:56 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif(t_game *all, int i, int j)
{
	int	c;
	int	p;
	int	e;

	i = 0;
	j = 0;
	while (all->map.mapi[i])
	{
		while (all->map.mapi[i][j])
		{
			if (all->map.mapi[i][j] == 'C')
				c++;
			if (all->map.mapi[i][j] == 'E')
				e++;
			if (all->map.mapi[i][j] == 'P')
				p++;
			j++;
		}
		j = 0;
		i++;
	}
	if (c != 0 || e != 0 || p != 0)
		finito(i);
	return (1);
}

int	ft_run9(t_game *all, int i, int j)
{
    if (all->map.mapi[i][j] == '0' || all->map.mapi[i][j] == 'C' || all->map.mapi[i][j] == 'E')
        all->map.mapi[i][j] = '9';
    if (all->map.mapi[i + 1] && (all->map.mapi[i + 1][j] == '0' || all->map.mapi[i + 1][j] == 'C' || all->map.mapi[i + 1][j] == 'E'))
    {
        i++;
        ft_run9(all, i, j);
    }
    if (i - 1 >= 0 && (all->map.mapi[i - 1][j] == '0' || all->map.mapi[i - 1][j] == 'C' || all->map.mapi[i - 1][j] == 'E'))
    {
        i--;
        ft_run9(all, i, j);
    }
    if (all->map.mapi[i][j + 1] == '0' || all->map.mapi[i][j + 1] == 'C' || all->map.mapi[i][j + 1] == 'E')
    {
        j++;
        ft_run9(all, i, j);
    }
    if (j - 1 >= 0 && (all->map.mapi[i][j - 1] == '0' || all->map.mapi[i][j - 1] == 'C' || all->map.mapi[i][j - 1] == 'E'))
    {
        j--;
        ft_run9(all, i, j);
    }
    return (0);
}

int	ft_parse_map(t_game *all)
{
	int i = 0;
	int j = 0;

	while (all->map.mapi[i] && all->map.mapi[i][j] != 'P')
	{
		if (all->map.mapi[i][j] == '\0' || all->map.mapi[i][j] == 10)
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	if (all->map.mapi[i])
	{
		all->map.mapi[i][j] = '9';
		ft_run9(all, i, j);
		//ft_verif(all, i ,j);
		if (all->cep.player == 1)
			return (0);
		else
			return (1);
	}
	else
		return (-1);
}
