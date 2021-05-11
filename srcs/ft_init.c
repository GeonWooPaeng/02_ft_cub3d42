/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:10:24 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/11 14:45:19 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"


double ft_init_player_dir(t_all *all)
{
	double rotation;

	rotation = 0;
	if (all->player.dir == EAST) //동쪽
		rotation = 0;
	else if (all->player.dir == SOUTH) //남쪽
		rotation = 90 * (PI / 180);
	else if (all->player.dir == WEST) // 서쪽
		rotation = 180 * (PI / 180);
	else if (all->player.dir == NORTH) //북쪽
		rotation = 270 * (PI / 180);
	return (rotation);
}

void	ft_init_player(t_all *all)
{
	all->player.x = 2;
	all->player.y = 5;
	all->player.dir_x = -1.0;
	all->player.dir_y = 0.0;
	all->player.plane_x = 0.0;
	all->player.plane_y = 0.66;
	all->player.move_speed = 0.1;
	all->player.rot_speed = 0.1;
	all->player.dir = 0;
}

void	ft_init_info(t_all *all)
{
	all->info.win_x = 0;
	all->info.win_y = 0;
	all->info.sprite_num = 0;
	all->map.width = 0;
	all->map.height = 0;
	all->map.tab = NULL;
	all->map.visited = NULL;
	all->tex.north_texture = NULL;
	all->tex.south_texture = NULL;
	all->tex.west_texture = NULL;
	all->tex.east_texture = NULL;
	all->tex.sprite_texture = NULL;
	all->tex.floor_color = 0;
	all->tex.ceiling_color = 0;
	all->tex.buf = NULL;
	all->tex.zbuf = NULL;
}

void ft_init_ray(t_all *all, int x)
{
	all->ray.camera_x = 2 * x / (double)all->info.win_x - 1;
	all->ray.dir_x = all->player.dir_x + all->player.plane_x * all->ray.camera_x;
	all->ray.dir_y = all->player.dir_y + all->player.plane_y * all->ray.camera_x;
	all->map.x = (int)all->player.x;
	all->map.y = (int)all->player.y;
	all->ray.delta_dist_x = fabs(1 / all->ray.dir_x);
	all->ray.delta_dist_y = fabs(1 / all->ray.dir_y);
	all->hit.h = 0;
}

