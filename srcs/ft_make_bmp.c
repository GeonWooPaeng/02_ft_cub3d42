/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:34:46 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/22 16:00:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	ft_int_to_char(unsigned char *tmp, int value)
{
	tmp[0] = (unsigned char)value;
	tmp[1] = (unsigned char)(value >> 8);
	tmp[2] = (unsigned char)(value >> 16);
	tmp[3] = (unsigned char)(value >> 24);
}

void	ft_bmp_header(t_all *all, int fd, int bmp_size)
{
	unsigned char	bmp_head[54];
	int				idx;

	idx = 0;
	while (idx < 54)
	{
		bmp_head[idx] = 0;
		idx += 1;
	}
	bmp_head[0] = (unsigned char)'B';
	bmp_head[1] = (unsigned char)'M';
	ft_int_to_char(bmp_head + 2, bmp_size);
	bmp_head[10] = (unsigned char)54; //file header + info header 크기 이자 오프셋, 음수이면 이미지 상하 반전
	bmp_head[14] = (unsigned char)40; //info header 크기
	ft_int_to_char(bmp_head + 18, all->info.win_x);
	ft_int_to_char(bmp_head + 22, all->info.win_y);
	bmp_head[26] = (unsigned char)1;
	bmp_head[28] = (unsigned char)24;
	write(fd, bmp_head, 54);
}

void	ft_bmp_data(t_all *all, int fd)
{
	int				win_h;
	int				win_w;
	int				pad_width;
	unsigned char	color_zero[3];

	color_zero[0] = 0;
	color_zero[1] = 0;
	color_zero[2] = 0;
	pad_width = (4 - (all->info.win_x * 3) % 4) % 4;
	win_h = 0;
	while (win_h < all->info.win_y)
	{
		win_w = 0;
		while (win_w < all->info.win_x)
		{
			write(fd, &(all->tex.buf[win_h][win_w]), 3);
			if (pad_width > 0)
				write(fd, &color_zero, pad_width);
			win_w += 1;
		}
		win_h += 1;
	}
}

void	ft_make_bmp(t_all *all)
{
	int	fd;
	int	bmp_size;

	bmp_size = 54 + 3 * all->info.win_x * all->info.win_y; //해상도 크기 만큼 4바이트(픽셀 당 바이트) 곱하고 헤더 더하기
	if ((fd = open("cub3D.bmp", O_WRONLY | O_CREAT |
	O_TRUNC , 00700)) < 0)
		ft_error("[ERROR] bmp file error");
	ft_bmp_header(all, fd, bmp_size);
	ft_bmp_data(all, fd);
}
