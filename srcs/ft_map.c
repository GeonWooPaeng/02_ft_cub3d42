/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:42:57 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/05 14:48:28 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_side_dist(t_info *info, t_map *map)
{// step_x,y, side_dist_x,y 넣어주는 곳
// 플레이어 기준 어느쪽인지 파악
	if (map->ray_direction_x < 0)
	{
		map->step_x = -1;
		map->side_dist_x = (info->player_position_x - map->map_x) * map->delta_dist_x;	
	}
	else
	{
		map->step_x = 1;
		map->side_dist_x = (map->map_x + 1.0 - info->player_position_x) * map->delta_dist_x;
	}
	if (map->ray_direction_y < 0)
	{
		map->step_y = -1;
		map->side_dist_y = (info->player_position_y - map->map_y) * map->delta_dist_y;
	}
	else
	{
		map->step_y = 1;
		map->side_dist_y = (map->map_y + 1.0 - info->player_position_y) * map->delta_dist_y;
	}
}

void	ft_hit_side(t_info *info, t_map *map)
{// 벽과 부딪쳤을 때까지 매번 한 칸씩 광선 이동하는 상황 
	while (map->hit == 0)
	{
		if (map->side_dist_x < map->side_dist_y)
		{
			map->side_dist_x += map->delta_dist_x;
			map->map_x += map->step_x;
			map->side = 0;
		}
		else
		{
			map->side_dist_y += map->delta_dist_y;
			map->map_y += map->step_y;
			map->side = 1;
		}
		if ((int)info->tab[map->map_x][map->map_y] > 0)
			map->hit = 1;
	}
	if (map->side == 0)
		map->perp_wall_dist = (map->map_x - info->player_position_x + (1 - map->step_x) / 2) / map->ray_direction_x;
	else
		map->perp_wall_dist = (map->map_y - info->player_position_y + (1 - map->step_y) / 2) / map->ray_direction_y;
}

void	ft_draw(t_info *info, t_map *map)
{// 스크린에 그릴 line의 높이 계산
	int	lineHeight;

	lineHeight = (int)(info->win_height / map->perp_wall_dist); //스크린에 그릴 line의 높이 계산
	// 선을 그릴 시작점과 끝점 구하기
	map->draw_start = (-lineHeight / 2) + (info->win_height / 2);
	map->draw_end = (lineHeight / 2) + (info->win_height / 2);
	if (map->draw_start < 0)
		map->draw_start = 0;
	if (map->draw_end >= info->win_height)
		map->draw_end = info->win_height - 1;
}

void	ft_wall(t_info *info, t_map *map)
{// wall_x이 어느 벽에 부딪쳤는지에 따라 값구하기
// 광선의 시작점에서 벽까지의 이동거리를 계산
	if (map->side == 0)
		map->wall_x = info->player_position_y + map->perp_wall_dist * map->ray_direction_y;
	else
		map->wall_x = info->player_position_x + map->perp_wall_dist * map->ray_direction_x;
	map->wall_x -= floor(map->wall_x);
}

void	ft_map_init(t_info *info, t_map *map, int x)
{
	double	cameraX; // x값이 카메라 평면 상에 있을 때의 좌표

	cameraX = (2 * x / (double)(info->win_width)) - 1;
	map->ray_direction_x = info->direction_vector_x + info->plane_x * cameraX;
	map->ray_direction_y = info->direction_vector_y + info->plane_y * cameraX;
	map->map_x = (int)(info->player_position_x);
	map->map_y = (int)(info->player_position_y);
	map->delta_dist_x = fabs(1 / map->ray_direction_x);
	map->delta_dist_y = fabs(1 / map->ray_direction_y);
	map->hit = 0;
}