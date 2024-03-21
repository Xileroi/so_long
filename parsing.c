/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:49:54 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/28 17:21:40 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_last(char *str, int i, int save, t_game *all)
{
	i = i - save;
	while (str[++i])
	{
		if (str[i] != '1')
			finitoi(all, str);
	}
	return (0);
}

int	ft_check_btw(char *str, int i, int save, t_game *all)
{
	int	j;
	int	k;

	j = 0;
	k = 2;
	while (str[++i])
	{
		j++;
		if (str[i + 1] == '\n' && str[i] == '1')
		{
			if (j != save)
				finitoi(all, str);
			j = 0;
			i++;
			all->map.height = ++k;
		}
		if (str[i + 1] == '\0' || (str[i + 1] == '\n' && str[i + 2] == '\0'))
		{
			if (save == j)
				ft_check_last(str, i, save, all);
			else
				finitoi(all, str);
		}
	}
	return (0);
}

int	ft_check_first(char *str, t_game *all)
{
	int	i;
	int	save;

	i = -1;
	while (str[++i] != '\n')
	{
		if (str[i] != '1')
			finitoi(all, str);
	}
	save = i;
	all->map.lenght = save;
	ft_check_btw(str, i, save, all);
	return (0);
}

int	ft_check_dependances(char *str, t_game *all)
{
	int	i;

	i = 0;
	all->cep.coins = 0;
	all->cep.exit = 0;
	all->cep.player = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			all->cep.coins++;
		if (str[i] == 'E')
			all->cep.exit++;
		if (str[i] == 'P')
			all->cep.player++;
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != '\n')
			finitoi(all, str);
		i++;
	}
	if (all->cep.exit != 1 || all->cep.coins <= 0
		|| all->cep.player != 1)
		finitoi(all, str);
	return (1);
}

void	map_read(int fd, t_game *all)
{
	int			i;
	char		**mapi;
	char		*str;
	char		*tmp;

	i = 0;
	str = get_next_line(fd);
	if (str == NULL)
		finitovoid(all);
	tmp = NULL;
	while (str != NULL)
	{
		i++;
		tmp = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(fd);
	}
	ft_check_first(tmp, all);
	ft_check_dependances(tmp, all);
	all->map.map = ft_split(tmp, '\n');
	mapi = ft_split(tmp, '\n');
	free(tmp);
	ft_parse_map(mapi, all);
	free_mapi(mapi);
}
