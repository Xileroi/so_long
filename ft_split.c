/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:52:40 by ylounici          #+#    #+#             */
/*   Updated: 2024/01/23 14:50:41 by yalounic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (s[0] != c && s[0])
		res++;
	i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i - 1] == c && s[i] != '\0')
			res++;
		if (s[i])
			i++;
	}
	return (res);
}

static char	**ini_tab(char **dest, const char *s, char c)
{
	int	i;
	int	res;
	int	j;

	j = 0;
	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			res++;
			i++;
			if (s[i] == c || !s[i])
			{
				dest[j] = malloc(sizeof(char) * (res + 1));
				res = 0;
				j++;
			}
		}
	}
	dest[j] = NULL;
	return (dest);
}

static char	**fil_tab(char **dest, const char *s, char c)
{
	int	i;
	int	res;
	int	j;

	j = 0;
	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			dest[j][res] = s[i];
			res++;
			i++;
			if (s[i] == c || !s[i])
			{
				dest[j][res] = '\0';
				res = 0;
				j++;
			}
		}
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (s == NULL || s[0] == '\0')
	{
		dest = malloc(sizeof(char *) * 1);
		dest[0] = NULL;
		return (dest);
	}
	dest = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	dest = ini_tab(dest, s, c);
	dest = fil_tab(dest, s, c);
	return (dest);
}
