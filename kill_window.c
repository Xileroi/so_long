/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:05:04 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/21 12:24:40 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *all)
{
	int	i;

	i = 0;
	while (all->map.map[i])
		free(all->map.map[i++]);
	free(all->map.map[i]);
}

void	free_mapi(char **mapi)
{
	int	i;

	i = 0;
	while (mapi[i])
		free(mapi[i++]);
	free(mapi[i]);
	free(mapi);
}

int	kill_window(t_game *all)
{
	free_map(all);
	exit(0);
}
