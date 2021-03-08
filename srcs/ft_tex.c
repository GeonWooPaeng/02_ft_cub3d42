/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:26:11 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/08 20:20:53 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_tex_x(t_map *map, t_tex *tex)
{
	tex->tex_x = (int)(map->wall_x * (double)TEX_WIDTH);
	if (map->side == 0 && map->ray_direction_x > 0)
		tex->tex_x = TEX_WIDTH - tex->tex_x - 1;
	if (map->side == 1 && map->ray_direction_y < 0)
		tex->tex_x = TEX_WIDTH - tex->tex_x - 1;
}

void	ft_tex_y(t_info *info, t_map *map, t_tex *tex, int x)
{
	int line_height;
	int y;

	y = map->draw_start;
	line_height = (int)(info->win_height / map->perp_wall_dist); //스크린에 그릴 line의 높이 계산
	tex->step = 1.0 * TEX_HEIGHT / line_height;
	tex->tex_pos = (map->draw_start - info->win_height / 2 + line_height / 2) * tex->step;
	while (y < map->draw_end)
	{
		tex->tex_y = (int)tex->tex_pos & (TEX_HEIGHT - 1);
		tex->tex_pos += tex->step;
		tex->color = info->texture[tex->tex_num][TEX_HEIGHT * tex->tex_y + tex->tex_x];
		if (map->side)
			tex->color = (tex->color >> 1) & 8355711;
		info->tab[y][x] = (char)tex->color;
		y++;
	}
}

void	ft_up_bottom(t_all *all)
{// 하늘과 바닥을 칠해주는 함수
	int x;
	int y;

	x = 0;
	while (x < all->info.win_x)
	{
		y = 0;
		while (y < all->info.win_y)
		{
			all->map.tab[y][x] = (char)info->ceiling_color;
			all->map.tab[all->info.win_y - y - 1][x] = (char)info->floor_color;
			y++;
		}
		x++;
	}
}