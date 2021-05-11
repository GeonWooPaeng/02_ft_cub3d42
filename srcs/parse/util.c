/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:11:01 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/22 17:01:53 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_cub3d.h"
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

int		ft_error(char *error)
{
	printf("%s", error);
	exit(0);
	return (0);
}

int ft_exit(int ret)
{
	exit(ret);
	return (ret);
}

int	ft_name_check(char *a, char *b)
{
	int idx;
	
	idx = 0;
	while (a[idx] != '\0')
		idx++;
	if (a[idx - 4] == b[0] && a[idx - 3] == b[1]
	&& a[idx - 2] == b[2] && a[idx - 1] == b[3])
		return (1);
	return (0);
}