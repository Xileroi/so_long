/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapable.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:00 by yalounic          #+#    #+#             */
/*   Updated: 2023/10/16 11:32:31 by yalounic         ###   ########.fr       */
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
	if (str[i][j] == '9')
	{
		if (str[i - 1][j] == '0' && i >= 1)
			str[i - 1][j] = '9';
		else if (str[i + 1][j] == '0' && i <= max_i)
			str[i + 1][j] = '9';
		else if (str[i][j - 1] == '0' && j >= 1)
			str[i][j - 1] = '9';
		else if (str[i][j + 1] == '0' && j <= ft_find_limit(str))
			str[i][j + 1] = '9';
	}
	while (i != 9)
	{
		i++;
		if (str[i][j] == 10)
		{
			j++;
			i = 0;
		}
	}
}

int	ft_parse_map(char **str, t_game *all)
{
	int	i;
	int	j;
	int	max_i;

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
			max_i = i;
			i = 0;
		}
	}
	str[i][j] = '9';
	ft_run9(str, i, j, max_i);
	if (all->cep.player == 1)
		return (0);
	else
		return (1);
}
