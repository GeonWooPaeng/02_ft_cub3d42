/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:23:52 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/22 17:02:31 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_cub3d.h"
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
	return (1);
}

void	ft_check_texture(t_all *all, char *arr, int type)
{
	if (type == NORTH)
		all->tex.north_texture = arr;
	else if (type == SOUTH)
		all->tex.south_texture = arr;
	else if (type == EAST)
		all->tex.east_texture = arr;
	else if (type == WEST)
		all->tex.west_texture = arr;
	else if (type == SPRITE)
		all->tex.sprite_texture = arr;
	else
		ft_error("[Error] more type texture");
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
		ft_error("[Error] texture malloc");
	*i = j;
	j = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		arr[j++] = line[(*i)++];
	arr[j] = '\0';
	if (!ft_name_check(arr, ".xpm"))
		return (ft_error("[Error] check .xpm file"));
	ft_check_texture(all, arr, type); // texture 값 채워주기
	return (1);
}

void		ft_color(t_all *all, char *line, int *i, int type)
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
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		ft_error("[Error] parsing color");
	color = (r * 256 * 256) + g * 256 + b;
	if (type == FLOOR)
		all->tex.floor_color = color;
	else if (type == CEILING)
		all->tex.ceiling_color = color;
}


