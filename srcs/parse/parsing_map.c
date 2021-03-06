/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:45:07 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/06 20:11:47 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_cub3d.h"

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

char		*ft_row(char *line, int *i)
{
	char	*tmp;
	int		idx;
	
	idx = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_rownum(line) + 1))))
		return (NULL);
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
	if (!(tmp = (char **)malloc(sizeof(char *) * (all->map.y + 2))))
		return (-1);
	while (idx < all->map.y)
	{
		tmp[idx] = all->map.tab[idx];
		idx++;
	}
	if ((tmp[all->map.y] = ft_row(line, i)) == NULL)
	{
		free(tmp);
		return (-1);
	}
	tmp[all->map.y + 1] = NULL;
	if (all->map.y > 0)
		free(all->map.tab);
	all->map.tab = tmp;
	all->map.y++;
	return (1);
}