/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:45:07 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/02 20:04:30 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_rownum(char *line)
{
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

char		*ft_row(t_all *all, char *line, int *i)
{
	char	*tmp;
	int		idx;
	
	idx = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_rownum(line) + 1))))
		return (-1);
	while (line[*i] != '\0')
	{
		if (line[*i] == '0' || line[*i] == '1' || line[*i] == '2' || 
		line[*i] == 'N' || line[*i] == 'S' || line[*i] == 'W' || 
		line[*i] == 'E')
			tmp[idx++] = line[*i];
		else if (line[*i] != ' ')
		{
			free(tmp);
			return (-1);
		}
		(*i)++;
	}
	tmp[idx] = '\0';
	return (tmp);
}

void	ft_map(t_all *all, char *line, int *i)
{
	char	**tmp;
	int		idx;

	idx = 0;
	if (!(tmp = (char *)malloc(sizeof(char *) * (all->info.map_height + 2))))
		return (-1);
	while (idx < all->info.map_height)
	{
		tmp[idx] = all->info.tab[idx];
		idx++;
	}
	if ((tmp[all->info.map_height] = ft_row(all, line, i)) == -1)
	{
		free(tmp);
		return (-1);
	}
	tmp[all->info.map_height + 1] = NULL;
	if (all->info.map_height > 0)
		free(all->info.tab);
	all->info.tab = tmp;
	all->info.map_height++;
	return (0);
}