/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:23:52 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/23 20:06:31 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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
	all->flag.r = 1;
	all->flag.cnt += 1;
	// printf("x: %d, y: %d", all->info.win_width, all->info.win_height);
	return (1);
}

void	ft_check_flag(t_all *all, int type)
{
	if (type == NORTH)
		all->flag.no = 1;
	else if (type == EAST)
		all->flag.ea = 1;
	else if (type == SOUTH)
		all->flag.so = 1;
	else if (type == WEST)
		all->flag.we = 1;
	else if (type == SPRITE)
		all->flag.s = 1;
	else if (type == FLOOR)
		all->flag.f = 1;
	else if (type == CEILING)
		all->flag.c = 1;
	all->flag.cnt += 1;
}

void	ft_check_texture(t_all *all, char *arr, int type)
{
	if (!all->flag.no && type == NORTH)
		all->tex.north_texture = arr;
	else if (!all->flag.so && type == SOUTH)
		all->tex.south_texture = arr;
	else if (!all->flag.ea && type == EAST)
		all->tex.east_texture = arr;
	else if (!all->flag.we && type == WEST)
		all->tex.west_texture = arr;
	else if (!all->flag.s && type == SPRITE)
		all->tex.sprite_texture = arr;
	ft_check_flag(all, type);
}

int		ft_texture(t_all *all, char *line, int *i, int type)
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
	ft_check_texture(all, arr, type); // texture 값 채워주기
	return (1);
}

int		ft_color(t_all *all, char *line, int *i, int type)
{
	int r;
	int g;
	int b;
	int color;
	
	(*i)++;
	ft_isspace(line, i);
	r = ft_atoi(line, i);
	(*i)++;
	g = ft_atoi(line, i);
	(*i)++;
	b = ft_atoi(line, i);
	// color = ((r << 16) || (g << 8) || b);
	color = (r * 256 * 256) + g * 256 + b;
	if (!all->flag.f && type == FLOOR)
		all->tex.floor_color = color;
	else if (!all->flag.c && type == CEILING)
		all->tex.ceiling_color = color;
	ft_check_flag(all, type);
	return (1);
}

