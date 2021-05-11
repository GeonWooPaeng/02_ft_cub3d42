/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:27:48 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/11 16:11:46 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_wall_texture(t_all *all)
{//wall_x이 어느 벽에 부딪쳤는지에 따라 값 구하기
// 광선의 시작점에서 벽까지의 이동거리를 계산
	if (all->hit.side <= 1)//동,서
		all->ray.wall_x = all->player.y
		+ all->ray.perp_wall_dist * all->ray.dir_y;
	else //남,북
		all->ray.wall_x = all->player.x
		+ all->ray.perp_wall_dist * all->ray.dir_x;
	all->ray.wall_x -= floor(all->ray.wall_x);

	//texture 계산
	//tex_x 지정하는 곳
	all->tex.x = (int)(all->ray.wall_x * (double)TEXTURE_WIDTH);
	if (all->hit.side == 1 || all->hit.side == 2)
		all->tex.x = TEXTURE_WIDTH - all->tex.x - 1;
}

void	ft_wall_color(t_all *all, int x)
{//tex_y 지정하는 곳
	int y;
	int color;

	y = all->ray.draw_start;
	all->tex.step = 1.0 * TEXTURE_HEIGHT / all->ray.line_height;
	all->tex.tex_pos = (all->ray.draw_start - all->info.win_y / 2
	+ all->ray.line_height / 2) * all->tex.step;
	while (y < all->ray.draw_end)
	{
		all->tex.y = (int)all->tex.tex_pos & (TEXTURE_HEIGHT - 1);
		all->tex.tex_pos += all->tex.step;
		color = all->tex.texture[all->hit.side]
		[TEXTURE_HEIGHT * all->tex.y + all->tex.x];
		if (all->hit.side <= 1)
			color = (color >> 1) & 8355711;
		all->tex.buf[y][x] = color;
		y++;
	}
}
