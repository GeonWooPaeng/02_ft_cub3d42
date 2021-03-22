/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:42:57 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/20 21:51:29 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
// //DDA 알고리즘
// for (x <- 0; x < SX) - SX: 화면 가로해상도 + ray의 개수
// {
// 	x번째에 해당하는 ray 각도 계산
// 	일차 함수 식 세우기(y = a(x-p) + q)- a: 기울기(tan), (p,q)
// 	while (벽에 안 닿을 동안)
// 		ray가 다음 세로선과 만나는 점 구하기
// 	while (벽에 안 닿을 동안)
// 		ray가 다음 가로선과 만나는 점 구하기
// 	ray가 닿은 세로선, 가로선 중 가까운 쪽을 진짜 닿는 벽으로 판정
// 	벽까지 거리 계산
// 	원근법에 따라 벽 세로선의 높이를 계산하여 화면에 그리기
// }

void	ft_side_dist(t_all *all)
{// step_x,y, side_dist_x,y 넣어주는 곳
// 플레이어 기준 어느쪽인지 파악
//step_x, step_y 계산 방법
// x좌표의 부호는 cos@, y좌표의 부호는 sin@와 같다
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
{// 벽과 부딪쳤을 때까지 매번 한 칸씩 광선 이동하는 상황(dda) 
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
