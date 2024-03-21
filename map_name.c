/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:35:38 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/23 14:34:21 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	ft_check_name(char *str, t_game *all)
{
	char	*ext;
	size_t	base;

	ext = ".ber";
	base = ft_strlen(str);
	if (base < 5)
		finito(all);
	while (*str)
		str++;
	str -= 4;
	if (ft_strncmp(str, ext, 4))
	{
		ft_printf("Error\nMauvaise extension.\n");
		exit(0);
	}
	else
		return (0);
	return (1);
}
