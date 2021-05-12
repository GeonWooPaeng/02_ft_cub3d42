/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:00:27 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/12 18:02:53 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/ft_cub3d.h"

int		ft_isspace(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n'
	|| line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int		ft_atoi(char *line, int *i)
{
	long num;

	num = 0;
	ft_isspace(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - '0');
		(*i)++;
	}
	return (num);
}

int		ft_name_check(char *a, char *b, int num)
{
	int idx;

	idx = 0;
	while (a[idx] != '\0')
		idx++;
	while(num > 0)
	{
		if (a[idx--] != b[num--])
			return (0);
	}
	return (1);
}
