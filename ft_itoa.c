/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylounici <ylounici@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:05:35 by ylounici          #+#    #+#             */
/*   Updated: 2022/06/05 01:08:27 by ylounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nlen(int c)
{
	int	i;

	i = 1;
	if (c < 0)
		i++;
	while (c / 10)
	{
		i++;
		c /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	nb;
	char		*str;
	int			posinega;
	int			len;

	nb = n;
	len = ft_nlen(nb);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	posinega = 1;
	if (n < 0)
	{
		str[0] = '-';
		posinega = -1;
	}
	str[len--] = '\0';
	str[len--] = ((n % 10) * posinega) + '0';
	while (n / 10)
	{
		n /= 10;
		str[len--] = ((n % 10) * posinega) + '0';
	}
	return (str);
}
