/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:35:22 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/12 16:44:16 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef FT_MAP_H
// # define FT_MAP_H

// typedef struct	s_map
// {
// 	double		ray_direction_x;// 광선의 방향 = 방향 벡터 + 카메라 평면 * 배수
// 	double		ray_direction_y;
// 	int			map_x; //현재 player가 위치한 맵 내 위치
// 	int			map_y;
// 	double		side_dist_x;
// 	double		side_dist_y; // 현재 위치에서 다음 사이드 까지의 거리
// 	double		delta_dist_x; //다음 X 까지의 광선의 이동거리
// 	double		delta_dist_y; //다음 Y 까지의 광선의 이동거리
// 	double		perp_wall_dist; //광선의 이동거리를 계산할 떄 필요한 변수
// 	int			step_x;//어느 방향으로 건너 뛰는가
// 	int			step_y;
// 	int			hit; //벽과 부딪혔는지 판별하기 위한 변수
// 	int			side; //어느 면에 부딪혔는지 파악(x == 0, y == 1)
// 	double		wall_x;
// 	int			draw_start;
// 	int			draw_end;
// }				t_map;

// void	ft_side_dist(t_info *info, t_map *map);
// void	ft_hit_side(t_info *info, t_map *map);
// void	ft_draw(t_info *info, t_map *map);
// void	ft_wall(t_info *info, t_map *map);
// void	ft_map_init(t_info *info, t_map *map, int x);

// #endif