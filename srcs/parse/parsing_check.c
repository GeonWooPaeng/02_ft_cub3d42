/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:43:11 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/20 18:43:15 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_map_check(t_all *all)
{
	int		col;
	int		row;
	char	p;
	
	col = 0;
	while (col < all->map.height)
	{
		row = 0;
		while (row < all->map.width)
		{
			p = all->map.tab[col][row];
			if (p != '1' && col == 0)
				ft_error("[Error] map error");
			else if (p != '1' && col == all->map.height - 1)
				ft_error("[Error] map error");
			else if (p != '1' && row == 0)
				ft_error("[Error] map error");
			else if (p != '1' && row == all->map.width - 1)
				ft_error("[Error] map error");
			row += 1;
		}
		col += 1;
	}
}

void	ft_player_check(t_all *all)
{
	int		row;
	int		col;
	char	p;

	col = 0;
	while (col < all->map.height)
	{
		row = 0;
		while (row < all->map.width)
		{
			p = all->map.tab[col][row];
			if (all->player.player_num > 1)
				ft_error("[Error] check player number");
			if (p == 'N' || p == 'E' || p == 'S' || p == 'W')
				all->player.player_num += 1;
			row += 1;
		}
		col += 1;
	}
}

int		ft_name_check(char *a, char *b, int num)
{
	int idx;

	idx = 0;
	while (a[idx] != '\0')
		idx++;
	while(num > 0)
	{
		if (a[idx--] != b[num--])
			return (0);
	}
	return (1);
}
