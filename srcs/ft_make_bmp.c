/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:34:46 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/15 19:25:29 by gpaeng           ###   ########.fr       */
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
	bmp_head[10] = (unsigned char)54;
	bmp_head[14] = (unsigned char)40;
	ft_int_to_char(bmp_head + 18, all->info.win_x);
	ft_int_to_char(bmp_head + 22, all->info.win_y);
	bmp_head[26] = (unsigned char)1;
	bmp_head[28] = (unsigned char)24;
	write(fd, bmp_head, 54);
}

void	ft_make_bmp(t_all *all)
{
	int	fd;
	int	bmp_size;

	bmp_size = 54 + 3 * all->info.win_x * all->info.win_y;
	if ((fd = open("cub3D.bmp", O_WRONLY | O_CREAT |
	O_TRUNC | O_APPEND, 00755)) < 0)
		return (0);
	ft_bmp_header(all, fd, bmp_size);
	ft_bmp_data(all, fd);
}
