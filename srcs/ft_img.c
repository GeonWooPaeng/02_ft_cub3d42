/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:09:56 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/02 16:49:52 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_up_bottom(t_all *all)
{// 하늘과 바닥을 칠해주는 함수
	int x;
	int y;

	x = 0;
	while (x < all->info.win_x)
	{
		y = 0;
		while (y < all->info.win_y)
		{
			all->tex.buf[y][x] = all->tex.ceiling_color;
			all->tex.buf[all->info.win_y - y - 1][x] = all->tex.floor_color;
			y++;
		}
		x++;
	}
}

void	ft_image_draw(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (y < all->info.win_y)
	{
		x = 0;
		while (x < all->info.win_x)
		{	
			all->img.data[all->info.win_x * y + x] = all->tex.buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->info.mlx, all->info.win, all->img.ptr, 0, 0);
}

void	load_image(t_all *all, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	img->ptr = mlx_xpm_file_to_image(all->info.mlx, path, &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{	
			texture[img->width * y + x] = img->data[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(all->info.mlx, img->ptr);
}

void		ft_load_texture(t_all *all)
{	
	t_img img;
	
	load_image(all, all->tex.texture[0], all->tex.east_texture, &img);// 동
	load_image(all, all->tex.texture[1], all->tex.west_texture, &img);// 서
	load_image(all, all->tex.texture[2], all->tex.south_texture, &img);// 남
	load_image(all, all->tex.texture[3], all->tex.north_texture, &img);// 북
	// load_image(all, all->tex.texture[4], all->tex.sprite_texture, &img);// 장애물
	free(all->tex.east_texture);
	all->tex.east_texture = NULL;
	free(all->tex.west_texture);
	all->tex.west_texture = NULL;
	free(all->tex.south_texture);
	all->tex.south_texture = NULL;
	free(all->tex.north_texture);
	all->tex.north_texture = NULL;
	// free(all->tex.sprite_texture);
	// all->tex.sprite_texture = NULL;
}

