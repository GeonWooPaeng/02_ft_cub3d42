/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:51:32 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/11 16:02:15 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void ft_sprite_heigth(t_all *all)
{
}

void ft_sprite_width(t_all *all)
{

}

void ft_sprite(t_all *all)
{
	int x;

	x = 0;
	while (x < all->info.sprite_num)
	{
		ft_sprite_height(all);
		ft_sprite_width(all);
		x++;
	}
}

void ft_init_sprite(t_all *all)
{
	int col;
	int row;
	int idx;

	all->sprite = (t_sprite *)malloc(sizeof(t_sprite) * all->info.sprite_num);
	col = 0;
	idx = 0;
	while (col < all->map.height)
	{
		row = 0;
		while (row < all->map.width)
		{
			if (all->map.tab[col][row] == '2')
			{
				all->sprite[idx].x = (double)row + 0.5f;
				all->sprite[idx].y = (double)col + 0.5f;
				idx++;
			}
			row++;
		}
		col++;
	}
}