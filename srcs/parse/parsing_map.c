/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:45:07 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/11 16:16:27 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

void	ft_player_dir(t_all *all, int col, int row)
{
	if (all->map.tab[col][row] == 'N')
		all->player.dir = NORTH;
	else if (all->map.tab[col][row] == 'E')
		all->player.dir = EAST;
	else if (all->map.tab[col][row] == 'S')
		all->player.dir = SOUTH;
	else if (all->map.tab[col][row] == 'W')
		all->player.dir = WEST;
}

void	ft_position(t_all *all)
{
	int		row;
	int		col;
	char	k;

	col = 0;
	while (col < all->map.height)
	{
		row = 0;
		while (row < all->map.width)
		{
			k = all->map.tab[col][row];
			if (k == 'N' || k == 'E' || k == 'S' || k == 'W')
			{
				all->player.x = (double)row + 0.5;
				all->player.y = (double)col + 0.5;
				ft_player_dir(all, col, row);
			}
			if (k == '2')
				all->info.sprite_num += 1;
			row += 1;
		}
		col += 1;
	}
}

int		ft_rownum(char *line)
{// 행 길이
	int	idx;
	int cnt;

	idx = 0;
	cnt = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '0' || line[idx] == '1' || line[idx] == '2' ||
		line[idx] == 'N' || line[idx] == 'S' || line[idx] == 'W' ||
		line[idx] == 'E')
			cnt++;
		idx++;
	}
	return (cnt);
}

char	*ft_row(char *line, int *i)
{// 행 malloc
	char	*tmp;
	int		idx;

	idx = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_rownum(line) + 1))))
		ft_error("[Error] rownum malloc");
	while (line[*i] != '\0')
	{
		if (line[*i] == '0' || line[*i] == '1' || line[*i] == '2' ||
		line[*i] == 'N' || line[*i] == 'S' || line[*i] == 'W' ||
		line[*i] == 'E')
			tmp[idx++] = line[*i];
		else if (line[*i] != ' ')
		{
			free(tmp);
			return (NULL);
		}
		(*i)++;
	}
	tmp[idx] = '\0';
	return (tmp);
}

int		ft_map(t_all *all, char *line, int *i)
{
	char	**tmp;
	int		idx;

	idx = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * (all->map.height + 2))))
		return (-1);
	while (idx < all->map.height)
	{
		tmp[idx] = all->map.tab[idx];
		idx++;
	}
	if ((tmp[all->map.height] = ft_row(line, i)) == NULL)
	{
		free(tmp);
		return (-1);
	}
	tmp[all->map.height + 1] = NULL;
	if (all->map.height > 0)
		free(all->map.tab);
	all->map.tab = tmp;
	all->map.height++;
	all->map.width = ft_rownum(line);
	return (1);
}
