/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:23:52 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/25 00:31:42 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_resolution(t_all *all, char *line, int *i)
{
	(*i)++;
	ft_isspace(line, i);
	all->info.win_x = ft_atoi(line, i);
	all->info.win_y = ft_atoi(line, i);
	if (all->info.win_x > 2560)
		all->info.win_x = 2560;
	if (all->info.win_y > 1400)
		all->info.win_y = 1400;
	// printf("x: %d, y: %d", all->info.win_x, all->info.win_y);
	return (1);
}

void	ft_texture(t_all *all, char *line, int *i)
{
	int		j;
	int		cnt;
	char	*arr;
	
	(*i) += 2;
	ft_isspace(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(arr = (char *)malloc(sizeof(char) * (*i - j + 1))))
		return (-1);
	cnt = 0;
	while (cnt < (*i - j + 1))
	{	
		arr[cnt] = line[*i + cnt];
		cnt++;
	}
	arr[cnt] = '\0';
	// printf("s >>> %s", arr);
	load_image(&(all->info), all->info.texture, arr, &(all->img));
	return (1);
}