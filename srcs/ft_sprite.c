/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:15:41 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/18 17:43:06 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/ft_cub3d.h"


void ft_sprite_dist(t_all *all)
{
	int idx;

	idx = 0;
	while (idx < all->info.sprite_num)
	{	//어디가 멀고 가까운지만 파악하기 위함으로 sqrt 안해도 됩니다.
		all->sprite[idx].distance = ((all->player.x - all->sprite[idx].x) * (all->player.x - all->sprite[idx].x)
		+ (all->player.y - all->sprite[idx].y) * (all->player.y - all->sprite[idx].y));
		idx++;
	}
	ft_rsort_sprite(all);
}

void ft_sprite_conversion(t_all *all, int x)
{
	all->sprite_ray.x = all->sprite[x].x - all->player.x;
	all->sprite_ray.y = all->sprite[x].y - all->player.y;
	all->sprite_ray.inv_det = 1.0 / (all->player.plane_x * all->player.dir_y
	- all->player.plane_y * all->player.dir_x);
	all->sprite_ray.transform_x = all->sprite_ray.inv_det *
	(all->player.dir_y * all->sprite_ray.x - all->player.dir_x * all->sprite_ray.y);
	all->sprite_ray.transform_y = all->sprite_ray.inv_det *
	(-all->player.plane_y * all->sprite_ray.x + all->player.plane_x * all->sprite_ray.y);
	all->sprite_ray.screen_x = (int)((all->info.win_x / 2) * 
	(1 + all->sprite_ray.transform_x / all->sprite_ray.transform_y));
	
}

void ft_sprite_hw(t_all *all)
{
	//height
	all->sprite_ray.height = abs((int)(all->info.win_y / all->sprite_ray.transform_y));
	all->sprite_ray.draw_start_y = -all->sprite_ray.height / 2 + all->info.win_y / 2;
	all->sprite_ray.draw_end_y = all->sprite_ray.height / 2 + all->info.win_y / 2;
	if (all->sprite_ray.draw_start_y < 0)
		all->sprite_ray.draw_start_y = 0;
	if (all->sprite_ray.draw_end_y >= all->info.win_y)
		all->sprite_ray.draw_end_y = all->info.win_y - 1;
	//width
	all->sprite_ray.width = abs((int)(all->info.win_y / all->sprite_ray.transform_y));
	all->sprite_ray.draw_start_x = -all->sprite_ray.width / 2 + all->sprite_ray.screen_x;
	all->sprite_ray.draw_end_x = all->sprite_ray.width / 2 + all->sprite_ray.screen_x;
	if (all->sprite_ray.draw_start_x < 0)
		all->sprite_ray.draw_start_x = 0;
	if (all->sprite_ray.draw_end_x >= all->info.win_x)
		all->sprite_ray.draw_end_x = all->info.win_x - 1;
}


void ft_sprite_color(t_all *all, int stripe)
{
	int draw_s_y;
	int draw;
	int color;
	
	all->sprite_tex.x = (int)(256 * (stripe 
	- (-all->sprite_ray.width / 2 + all->sprite_ray.screen_x))
	* TEXTURE_WIDTH / all->sprite_ray.width) / 256;
	if (all->sprite_ray.transform_y > 0 && stripe > 0 && stripe < all->info.win_x
	&& all->sprite_ray.transform_y < all->tex.zbuf[stripe])
	{
		draw_s_y = all->sprite_ray.draw_start_y;
		while (draw_s_y < all->sprite_ray.draw_end_y)
		{
			draw = (draw_s_y - 1) * 256 - all->info.win_y * 128 
			+ all->sprite_ray.height * 128;
			all->sprite_tex.y = ((draw * TEXTURE_HEIGHT) 
			/ all->sprite_ray.height) / 256;
			color = all->tex.texture[4]
			[TEXTURE_WIDTH * all->sprite_tex.y + all->sprite_tex.x];
			if ((color & 0x00FFFFFF) != 0)
				all->tex.buf[draw_s_y][stripe] = color;
			draw_s_y++;
		}
	}
}

void ft_sprite(t_all *all)
{
	int x;
	int draw_s_x;
	int draw_e_x;

	x = 0;
	ft_sprite_dist(all);
	while (x < all->info.sprite_num)
	{
		ft_sprite_conversion(all, x);
		ft_sprite_hw(all);
		draw_s_x = all->sprite_ray.draw_start_x;
		draw_e_x = all->sprite_ray.draw_end_x;
		while (draw_s_x < draw_e_x)
		{
			ft_sprite_color(all, draw_s_x);
			draw_s_x++;
		}
		x++;
	}
}

