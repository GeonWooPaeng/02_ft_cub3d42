/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:48:23 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/25 21:46:29 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void ft_move_ws(t_all *all, double speed)
{
	if (all->map.tab[(int)all->player.y]
	[(int)(all->player.x + all->player.dir_x * speed)] != '1')
		all->player.x += all->player.dir_x * speed;
	if (all->map.tab[(int)(all->player.y + all->player.dir_y * speed)]
	[(int)all->player.x] != '1')
		all->player.y += all->player.dir_y * speed;
}

void ft_move_ad(t_all *all, double speed)
{
	if (all->map.tab[(int)all->player.y]
	[(int)(all->player.x + all->player.dir_y * speed)] != '1')
		all->player.x += all->player.dir_y * speed;
	if (all->map.tab[(int)(all->player.y + -all->player.dir_x * speed)]
	[(int)all->player.x] != '1')
		all->player.y += -all->player.dir_x * speed;
}

void ft_rotate_player(t_all *all, double speed)
{
	double old_dir_x;
	double old_plane_x;
	 
	old_dir_x = all->player.dir_x;
	all->player.dir_x = all->player.dir_x * cos(speed) - all->player.dir_y * sin(speed);
	all->player.dir_y = old_dir_x * sin(speed) + all->player.dir_y * cos(speed);
	old_plane_x = all->player.plane_x;
	all->player.plane_x = all->player.plane_x * cos(speed) - all->player.plane_y * sin(speed);
	all->player.plane_y = old_plane_x * sin(speed) + all->player.plane_y * cos(speed);
}

int		ft_key_press(int key, t_all *all)
{	
	if (key == KEY_W)
		ft_move_ws(all, all->player.move_speed);
	if (key == KEY_S)
		ft_move_ws(all, -all->player.move_speed);
	if (key == KEY_A)
		ft_move_ad(all, -all->player.move_speed);
	if (key == KEY_D)
		ft_move_ad(all, all->player.move_speed);
	if (key == LEFT)
		ft_rotate_player(all, all->player.rot_speed);
	if (key == RIGHT)
		ft_rotate_player(all, -all->player.rot_speed);
	if (key == ESC)
		exit(0);
	return (0);
}
