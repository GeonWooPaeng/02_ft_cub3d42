/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:37:25 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/08 20:55:58 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_key_w(t_all *all)
{
	if (!all->map.tab[(int)(all->pos.x + all->dir.x * 0.05)][(int)(all->pos.y)])
		all->pos.x += all->dir.x * 0.05;
	if (!all->map.tab[(int)(all->pos.x)][(int)(all->pos.y + all->dir.y * 0.05)])
		all->pos.y += all->dir.y * 0.05;
}

void	ft_key_s(t_all *all)
{
	if (!all->map.tab[(int)(all->pos.x - all->dir.x * 0.05)][(int)(all->pos.y)])
		all->pos.x -= all->dir.x * 0.05;
	if (!all->map.tab[(int)(all->pos.x)][(int)(all->pos.y - all->dir.y * 0.05)])
		all->pos.y -= all->dir.y * 0.05;
}

void	ft_key_a(t_all *all)
{
	double oldDirectionX = all->dir.x;
	all->dir.x = all->dir.x * cos(0.05) - all->dir.y * sin(0.05);
	all->dir.y = oldDirectionX * sin(0.05) + all->dir.y * cos(0.05);
	double oldPlaneX = all->plane.x;
	all->plane.x = all->plane.x * cos(0.05) - all->plane.y * sin(0.05);
	all->plane.y = oldPlaneX * sin(0.05) + all->plane.y * cos(0.05);
}

void	ft_key_d(t_all *all)
{
	double oldDirectionX = all->dir.x;
	all->dir.x = all->dir.x * cos(-0.05) - all->dir.y * sin(-0.05);
	all->dir.y = oldDirectionX * sin(-0.05) + all->dir.y * cos(-0.05);
	double oldPlaneX = all->plane.x;
	all->plane.x = all->plane.x * cos(-0.05) - all->plane.y * sin(-0.05);
	all->plane.y = oldPlaneX * sin(-0.05) + all->plane.y * cos(-0.05);
}

int		key_press(int key, t_all *all)
{
	if (key == KEY_W)
		ft_key_w(all);
	if (key == KEY_S)
		ft_key_s(all);
	if (key == KEY_A)
		ft_key_a(all);
	if (key == KEY_D)
		ft_key_d(all);
	if (key == K_ESC)
		exit(0);
	return (0);
}
