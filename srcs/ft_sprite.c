/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:51:32 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/11 17:56:30 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void ft_sort_sprite(t_all *all)
{
	int i;
	int j;
	int min_idx;
	t_sprite tmp;
	
	i = 0;
	while (i < all->info.sprite_num)
	{
		min_idx = i;
		j = i + 1;
		while (j < all->info.sprite_num)
		{
			if (all->sprite[min_idx].distance > all->sprite[j].distance)
				min_idx = j;
			j++;
		}
		tmp = all->sprite[i];
		all->sprite[i] = all->sprite[min_idx];
		all->sprite[min_idx] = tmp;
		i++;
	}

}

void ft_sprite_dist(t_all *all)
{
	int idx;

	idx = 0;
	while (idx < all->info.sprite_num)
	{	//어디가 멀고 가까운지만 파악하기 위함으로 sqrt 안해도 됩니다.
		all->sprite[idx].distance = ((all->player.x - all->sprite[idx].x) * (all->player.x - all->sprite[idx].x)
		+ (all->player.y - all->sprite[idx].y) * (all->player.y - all->sprite[idx].y));
		idx++;
	}
	ft_sort_sprite(all);
}

void ft_sprite(t_all *all)
{
	int x;

	x = 0;
	ft_sprite_dist(all);
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
				all->sprite[idx].x = (double)row + 0.5;
				all->sprite[idx].y = (double)col + 0.5;
				idx++;
			}
			row++;
		}
		col++;
	}
}