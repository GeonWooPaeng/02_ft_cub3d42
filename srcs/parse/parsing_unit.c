/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:23:52 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/06 20:31:57 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

int		ft_resolution(t_all *all, char *line, int *i)
{
	(*i)++;
	ft_isspace(line, i);
	all->info.win_x= ft_atoi(line, i);
	all->info.win_y = ft_atoi(line, i);
	if (all->info.win_x > 2560)
		all->info.win_x = 2560;
	if (all->info.win_y > 1400)
		all->info.win_y = 1400;
	// printf("x: %d, y: %d", all->info.win_width, all->info.win_height);
	return (1);
}

int		ft_texture(t_all *all, char *line, int *i, int *idx)
{
	char	*arr;
	int		j;
	
	(*i) += 2;
	ft_isspace(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(arr = (char *)malloc(sizeof(char) * (*i - j + 1))))
		return (-1);
	*i = j;
	j = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		arr[j++] = line[(*i)++];
	arr[j] = '\0';
	// load_image(&(all->info), all->info.texture[*idx], arr, &(all->img));
	(*idx)++;
	return (1);
}

int		ft_color(t_all *all, char *line, int *i)
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
	// color = ((r << 16) || (g << 8) || b);
	color = (r * 256 * 256) + g * 256 + b;
	// if (fc_check)
	// 	all->info.floor_color = color;
	// else
	// 	all->info.ceiling_color = color;
	printf("color >> %d, %d, %d\n",r, g, b);
	return (1);
}

