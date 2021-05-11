/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:17:06 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/22 16:50:40 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_init_texture(t_all *all)
{
	int i;
	int j;
	
	if (!(all->tex.texture = (int **)malloc(sizeof(int *) * 5)))
		return (0);
	i = 0;
	while (i < 5)
	{
		if (!(all->tex.texture[i] = (int *)malloc(sizeof(int) * TEXTURE_WIDTH * TEXTURE_HEIGHT)))
			return (0);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
			all->tex.texture[i][j++] = 0;
		i++;
	}
	ft_load_texture(all);
	return (1);
}

int		ft_init_buffer(t_all *all)
{
	int i;
	int j;
	
	if (!(all->tex.buf = (int **)malloc(sizeof(int *) * all->info.win_y)))
		return (0);
	i = 0;
	while (i < all->info.win_y)
		if (!(all->tex.buf[i++] = (int *)malloc(sizeof(int) * all->info.win_x)))
			return (0);
	i = 0;
	while (i < all->info.win_y)
	{
		j = 0;
		while (j < all->info.win_x)
			all->tex.buf[i][j++] = 0;
		i++;
	}
	return (1);
}

int	ft_init_zbuffer(t_all *all)
{
	int i;

	if (!(all->tex.zbuf = (double *)malloc(sizeof(double) * all->info.win_y)))
		return (0);
	i = 0;
	while (i < all->info.win_y)
	{
		all->tex.zbuf[i] = 0;
		i++;
	}
	return (1);
}


