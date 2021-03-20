/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:37:25 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/20 14:21:18 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

// void	ft_key_w(t_all *all)
// {
// 	if (!all->map.tab[(int)(all->pos.x + all->dir.x * 0.05)][(int)(all->pos.y)])
// 		all->pos.x += all->dir.x * 0.05;
// 	if (!all->map.tab[(int)(all->pos.x)][(int)(all->pos.y + all->dir.y * 0.05)])
// 		all->pos.y += all->dir.y * 0.05;
// }

// void	ft_key_s(t_all *all)
// {
// 	if (!all->map.tab[(int)(all->pos.x - all->dir.x * 0.05)][(int)(all->pos.y)])
// 		all->pos.x -= all->dir.x * 0.05;
// 	if (!all->map.tab[(int)(all->pos.x)][(int)(all->pos.y - all->dir.y * 0.05)])
// 		all->pos.y -= all->dir.y * 0.05;
// }

// void	ft_key_a(t_all *all)
// {
// 	if (!all->map.tab[(int)(all->pos.y)][(int)(all->pos.x + all->dir.y * -0.05)])
// 		all->pos.x += all->dir.x * -0.05;
// 	if (!all->map.tab[(int)(all->pos.y - all->dir.y * -0.05)][(int)(all->pos.x)])
// 		all->pos.y += -(all->dir.y) * -0.05;
// }

// void	ft_key_d(t_all *all)
// {
// 	if (!all->map.tab[(int)(all->pos.y)][(int)(all->pos.x + all->dir.y * 0.05)])
// 		all->pos.x += all->dir.x * 0.05;
// 	if (!all->map.tab[(int)(all->pos.y - all->dir.y * 0.05)][(int)(all->pos.x)])
// 		all->pos.y += -(all->dir.y) * 0.05;
// }

// void	ft_key_right_left(t_all *all, double move_speed)
// {
// 	double oldDirectionX = all->dir.x;
// 	all->dir.x = all->dir.x * cos(move_speed) - all->dir.y * sin(move_speed);
// 	all->dir.y = oldDirectionX * sin(move_speed) + all->dir.y * cos(move_speed);
// 	double oldPlaneX = all->plane.x;
// 	all->plane.x = all->plane.x * cos(move_speed) - all->plane.y * sin(move_speed);
// 	all->plane.y = oldPlaneX * sin(move_speed) + all->plane.y * cos(move_speed);
// }

// int		key_press(int key, t_all *all)
// {	
// 	if (key == KEY_W)
// 		ft_key_w(all);
// 	if (key == KEY_S)
// 		ft_key_s(all);
// 	if (key == KEY_A)
// 		ft_key_a(all);
// 	if (key == KEY_D)
// 		ft_key_d(all);
// 	if (key == LEFT)
// 		ft_key_right_left(all, 0.05);
// 	if (key == RIGHT)
// 		ft_key_right_left(all, -0.05);
// 	if (key == ESC)
// 		exit(0);
// 	return (0);
// }
