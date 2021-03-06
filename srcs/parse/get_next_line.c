/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:38:02 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/06 20:07:35 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

size_t		ft_strlen(const char *str)
{
	size_t cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

char		*ft_strndup(const char *str, size_t num)
{
	char	*arr;
	size_t	idx;

	if (!(arr = (char *)malloc(sizeof(char) * (num + 1))))
		return (0);
	idx = 0;
	while (*str && idx < num)
	{
		arr[idx++] = *str;
		str++;
	}
	arr[idx] = '\0';
	return (arr);
}

char		*ft_strjoin(const char *a, const char *b)
{
	char	*arr;
	size_t	idx;
	size_t	alen;
	size_t	blen;

	alen = ft_strlen(a);
	blen = ft_strlen(b);
	if (!(arr = (char *)malloc(sizeof(char) * (alen + blen + 1))))
		return (0);
	idx = 0;
	while (a[idx] && idx < alen)
	{
		arr[idx] = a[idx];
		idx++;
	}
	idx = 0;
	while (b[idx] && idx < blen)
	{
		arr[idx + alen] = b[idx];
		idx++;
	}
	arr[alen + blen] = '\0';
	return (arr);
}

char		*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (0);
}