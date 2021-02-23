/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:37:25 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/23 19:02:27 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_key_w(t_info *info)
{
	if (!world_map[(int)(info->player_position_x + info->direction_vector_x * info->move_speed)][(int)(info->player_position_y)])
		info->player_position_x += info->direction_vector_x * info->move_speed;
	if (!world_map[(int)(info->player_position_x)][(int)(info->player_position_y + info->direction_vector_y * info->move_speed)])
		info->player_position_y += info->direction_vector_y * info->move_speed;
}

void	ft_key_s(t_info *info)
{
	if (!world_map[(int)(info->player_position_x - info->direction_vector_x * info->move_speed)][(int)(info->player_position_y)])
		info->player_position_x -= info->direction_vector_x * info->move_speed;
	if (!world_map[(int)(info->player_position_x)][(int)(info->player_position_y - info->direction_vector_y * info->move_speed)])
		info->player_position_y -= info->direction_vector_y * info->move_speed;
}

void	ft_key_a(t_info *info)
{
	double oldDirectionX = info->direction_vector_x;
	info->direction_vector_x = info->direction_vector_x * cos(info->rot_speed) - info->direction_vector_y * sin(info->rot_speed);
	info->direction_vector_y = oldDirectionX * sin(info->rot_speed) + info->direction_vector_y * cos(info->rot_speed);
	double oldPlaneX = info->plane_x;
	info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
	info->plane_y = oldPlaneX * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
}

void	ft_key_d(t_info *info)
{
	double oldDirectionX = info->direction_vector_x;
	info->direction_vector_x = info->direction_vector_x * cos(-info->rot_speed) - info->direction_vector_y * sin(-info->rot_speed);
	info->direction_vector_y = oldDirectionX * sin(-info->rot_speed) + info->direction_vector_y * cos(-info->rot_speed);
	double oldPlaneX = info->plane_x;
	info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
	info->plane_y = oldPlaneX * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
}

int		key_press(int key, t_info *info)
{
	if (key == KEY_W)
		ft_key_w(info);
	if (key == KEY_S)
		ft_key_s(info);
	if (key == KEY_A)
		ft_key_a(info);
	if (key == KEY_D)
		ft_key_d(info);
	if (key == K_ESC)
		exit(0);
	return (0);
}
