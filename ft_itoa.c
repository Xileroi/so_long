/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:05:35 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/25 16:48:22 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_itoa_size(long nbr)
{
	int	size;

	size = 1;
	if (nbr < 0)
		size++;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static void	ft_itoa_fill(char *sptr, int *index, long nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr >= 10)
	{
		ft_itoa_fill(sptr, index, nbr / 10);
		ft_itoa_fill(sptr, index, nbr % 10);
	}
	else
	{
		sptr[*index] = nbr + '0';
		(*index)++;
	}
}

char	*ft_itoa(int n)
{
	char	*sptr;
	int		index;
	long	nbr;

	nbr = n;
	sptr = (char *)ft_calloc(ft_itoa_size(nbr) + 1, sizeof(char));
	if (!sptr)
		return (NULL);
	index = 0;
	if (nbr < 0)
	{
		sptr[index++] = '-';
	}
	ft_itoa_fill(sptr, &index, nbr);
	sptr[index] = '\0';
	return (sptr);
}
