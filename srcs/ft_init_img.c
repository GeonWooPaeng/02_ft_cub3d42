/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:17:06 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/02 16:11:57 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_init_texture(t_all *all)
{
	int i;
	int j;
	
	if (!(all->tex.texture = (int **)malloc(sizeof(int *) * 5)))
		return (-1);
	i = 0;
	while (i < 5)
	{
		if (!(all->tex.texture[i] = (int *)malloc(sizeof(int) * TEXTURE_WIDTH * TEXTURE_HEIGHT)))
			return (-1);
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
	return (0);
}

void	ft_init_buffer(t_all *all)
{
	int i;
	int j;
	
	all->tex.buf = (int **)malloc(sizeof(int *) * all->info.win_y);
	i = 0;
	while (i < all->info.win_y)
		all->tex.buf[i++] = (int *)malloc(sizeof(int) * all->info.win_x);
	i = 0;
	while (i < all->info.win_y)
	{
		j = 0;
		while (j < all->info.win_x)
			all->tex.buf[i][j++] = 0;
		i++;
	}
}


