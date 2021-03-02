/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:23:52 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/02 19:45:16 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_resolution(t_all *all, char *line, int *i)
{
	(*i)++;
	ft_isspace(line, i);
	all->info.win_width = ft_atoi(line, i);
	all->info.win_height = ft_atoi(line, i);
	if (all->info.win_width > 2560)
		all->info.win_width = 2560;
	if (all->info.win_height > 1400)
		all->info.win_height = 1400;
	// printf("x: %d, y: %d", all->info.win_width, all->info.win_height);
	return (1);
}

void	ft_texture(t_all *all, char *line, int *i, int *idx)
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
	load_image(&(all->info), all->info.texture[*idx], arr, &(all->img));
	(*idx)++;
	return (1);
}

void	ft_color(t_all *all, char *line, int *i)
{
	int r;
	int g;
	int b;
	int color;
	int fc_check;
	
	fc_check = 1;
	if (line[*i] == 'C')
		fc_check = 0;
	(*i)++;
	ft_isspace(line, i);
	r = ft_atoi(line, i);
	(*i)++;
	g = ft_atoi(line, i);
	(*i)++;
	b = ft_atoi(line, i);
	color = ((r << 16) || (g << 8) || b);
	// color = (r * 256 * 256) + g * 256 + b;
	if (fc_check)
		all->info.floor_color = color;
	else
		all->info.ceiling_color = color;
	return (1);
}

