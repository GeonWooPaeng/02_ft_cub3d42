/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:16:54 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/11 16:01:04 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	ft_rsort_sprite(t_all *all)
{ //원거리 -> 가까운 순
	int i;
	int j;
	int max_idx;
	t_sprite tmp;

	i = 0;
	while (i < all->info.sprite_num - 1)
	{
		max_idx = i;
		j = i + 1;
		while (j < all->info.sprite_num)
		{
			if (all->sprite[max_idx].distance < all->sprite[j].distance)
				max_idx = j;
			j++;
		}
		tmp = all->sprite[i];
		all->sprite[i] = all->sprite[max_idx];
		all->sprite[max_idx] = tmp;
		i++;
	}
}

void	ft_init_sprite(t_all *all)
{
	int idx;

	idx = 0;
	while (idx < all->info.sprite_num - 1)
	{
		all->sprite[idx].x = 0;
		all->sprite[idx].y = 0;
		all->sprite[idx].distance = 0;
		idx += 1;
	}
}

void	ft_set_sprite(t_all *all)
{
	int col;
	int row;
	int idx;

	all->sprite = (t_sprite *)malloc(sizeof(t_sprite) * all->info.sprite_num);
	ft_init_sprite(all);
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
				idx += 1;
			}
			row += 1;
		}
		col += 1;
	}
}
