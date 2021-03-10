/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:42:57 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/10 15:03:30 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_side_dist(t_all *all)
{// step_x,y, side_dist_x,y 넣어주는 곳
// 플레이어 기준 어느쪽인지 파악
	if (all->ray.x < 0)
	{
		all->ray.step_x = -1;
		all->pos.side_dist_x = (all->pos.x - all->map.x) * all->ray.delta_dist_x;	
	}
	else
	{
		all->ray.step_x = 1;
		all->pos.side_dist_x = (all->map.x + 1.0 - all->pos.x) * all->ray.delta_dist_x;
	}
	if (all->ray.y < 0)
	{
		all->ray.step_y = -1;
		all->pos.side_dist_y = (all->pos.y - all->map.y) * all->ray.delta_dist_y;
	}
	else
	{
		all->ray.step_y = 1;
		all->pos.side_dist_y = (all->map.y + 1.0 - all->pos.y) * all->ray.delta_dist_y;
	}
}

void	ft_hit_side(t_all *all)
{// 벽과 부딪쳤을 때까지 매번 한 칸씩 광선 이동하는 상황 
	while (all->hit.h == 0)
	{
		if (all->pos.side_dist_x < all->pos.side_dist_y)
		{
			all->pos.side_dist_x += all->ray.delta_dist_x;
			all->map.x += all->ray.step_x;
			all->hit.side = 0;
		}
		else
		{
			all->pos.side_dist_y += all->ray.delta_dist_x;
			all->map.y += all->ray.step_y;
			all->hit.side = 1;
		}
		if ((int)all->map.tab[all->map.x][all->map.y] > 0)
			all->hit.h = 1;
	}
	if (all->hit.side == 0)
		all->ray.perp_wall_dist = (all->map.x - all->pos.x + (1 - all->ray.step_x) / 2) / all->ray.x;
	else
		all->ray.perp_wall_dist = (all->map.y - all->pos.y + (1 - all->ray.step_y) / 2) / all->ray.y;
}

void	ft_draw(t_all *all)
{// 스크린에 그릴 line의 높이 계산
	int	lineHeight;

	lineHeight = (int)(all->info.win_y / all->ray.perp_wall_dist); //스크린에 그릴 line의 높이 계산
	// 선을 그릴 시작점과 끝점 구하기
	all->img.draw_start = (-lineHeight / 2) + (all->info.win_y / 2);
	all->img.draw_end = (lineHeight / 2) + (all->info.win_y / 2);
	if (all->img.draw_start < 0)
		all->img.draw_start = 0;
	if (all->img.draw_end >= all->info.win_y)
		all->img.draw_end = all->info.win_y - 1;
}

void	ft_wall(t_all *all)
{// wall_x이 어느 벽에 부딪쳤는지에 따라 값구하기
// 광선의 시작점에서 벽까지의 이동거리를 계산
	if (all->hit.side == 0)
		all->ray.wall_x = all->pos.y + all->ray.perp_wall_dist * all->ray.y;
	else
		all->ray.wall_x = all->pos.x + all->ray.perp_wall_dist * all->ray.x;
	all->ray.wall_x -= floor(all->ray.wall_x);
}

void	ft_map_init(t_all *all, int x)
{
	double	cameraX; // x값이 카메라 평면 상에 있을 때의 좌표

	cameraX = (2 * x / (double)(all->info.win_x)) - 1;
	all->ray.x = all->dir.x + all->plane.x * cameraX;
	all->ray.y = all->dir.y + all->plane.y * cameraX;
	all->map.x = (int)(all->pos.x);
	all->map.x = (int)(all->pos.y);
	all->ray.delta_dist_x = fabs(1 / all->ray.x);
	all->ray.delta_dist_y = fabs(1 / all->ray.y);
	all->hit.h = 0;
}