/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:26:11 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/13 14:40:31 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_tex_x(t_all *all)
{
	all->tex.x = (int)(all->ray.wall_x * (double)64);
	if (all->hit.side == 0 && all->ray.x > 0)
		all->tex.x = 64 - all->tex.x - 1;
	if (all->hit.side == 1 && all->ray.y < 0)
		all->tex.x = 64 - all->tex.x - 1;
}

void	ft_tex_y(t_all *all, int x)
{
	int line_height;
	int y;

	y = all->img.draw_start;
	line_height = (int)(all->info.win_y / all->ray.perp_wall_dist); //스크린에 그릴 line의 높이 계산
	all->tex.step = 1.0 * 64 / line_height;
	all->tex.tex_pos = (all->img.draw_start - all->info.win_y / 2 + line_height / 2) * all->tex.step;
	while (y < all->img.draw_end)
	{
		all->tex.y = (int)all->tex.tex_pos & (64 - 1);
		all->tex.tex_pos += all->tex.step;
		all->tex.color = all->img.texture[all->tex.tex_num][64 * all->tex.y + all->tex.x];
		if (all->hit.side)
			all->tex.color = (all->tex.color >> 1) & 8355711;
		all->img.buf[y][x] = all->tex.color;
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
			all->img.buf[y][x] = all->tex.ceiling_color;
			all->img.buf[all->info.win_y - y - 1][x] = all->tex.floor_color;
			y++;
		}
		x++;
	}
}