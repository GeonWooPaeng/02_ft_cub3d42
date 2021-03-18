/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:09:56 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/13 15:17:07 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	image_draw(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (y < all->info.win_y)
	{
		x = 0;
		while (x < all->info.win_x)
		{	
			all->img.data[y * all->info.win_x + x] = (int)all->map.tab[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->info.mlx, all->info.win, all->img.ptr, 0, 0);
}

// void	load_texture(t_info *info)
// {
// 	t_img	img;
	
// 	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
// 	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
// 	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
// 	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
// 	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
// 	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
// 	load_image(info, info->texture[6], "textures/wood.xpm", &img);
// 	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
// }

void	load_image(t_all *all, char *file)
{
	int x;
	int y;
	int	
	all->img.ptr = mlx_xpm_file_to_image(all->info.mlx, file, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{	
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}