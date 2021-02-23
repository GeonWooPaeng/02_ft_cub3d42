/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:26:11 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/23 19:22:34 by gpaeng           ###   ########.fr       */
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
	int lineHeight;
	int y;

	y = map->draw_start;
	lineHeight = (int)(SCREEN_HEIGHT / map->perp_wall_dist); //스크린에 그릴 line의 높이 계산
	tex->step = 1.0 * TEX_HEIGHT / lineHeight;
	tex->tex_pos = (map->draw_start - SCREEN_HEIGHT / 2 + lineHeight / 2) * tex->step;
	while (y < map->draw_end)
	{
		tex->tex_y = (int)tex->tex_pos & (TEX_HEIGHT - 1);
		tex->tex_pos += tex->step;
		tex->color = info->texture[tex->tex_num][TEX_HEIGHT * tex->tex_y + tex->tex_x];
		if (map->side)
			tex->color = (tex->color >> 1) & 8355711;
		info->buf[y][x] = tex->color;
		y++;
	}
}

void	ft_up_bottom(t_info *info)
{
	int x;
	int y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			info->buf[y][x] = 0xFFFF00;
			info->buf[SCREEN_HEIGHT - y - 1][x] = 0x000000;
			y++;
		}
		x++;
	}
}