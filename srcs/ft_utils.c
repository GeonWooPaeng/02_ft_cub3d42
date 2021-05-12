/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:04:16 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/12 18:44:43 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	ft_free_1(void *arr)
{
	free(arr);
	arr = 0;
}

void	ft_free_2(char **arr)
{
	int idx;

	idx = 0;
	while (arr[idx])
		free(arr[idx++]);
	free(arr);
}

void	ft_free(t_all *all)
{
	if (all->info.mlx)
		ft_free_1(all->info.mlx);
	if (all->info.win)
		ft_free_1(all->info.win);
	if (all->img.ptr)
		mlx_destroy_image(all->info.mlx, all->img.ptr);
	if (all->map.tab)
		ft_free_2(all->map.tab);
	if (all->tex.texture)
		ft_free_1(all->tex.texture);
	if (all->tex.buf)
		ft_free_1(all->tex.buf);
	if (all->tex.zbuf)
		ft_free_1(all->tex.zbuf);
	if (all->sprite)
		ft_free_1(all->sprite);
}

int		ft_error(char *error)
{
	printf("%s", error);
	ft_exit(0);
	return (0);
}

int		ft_exit(int ret)
{
	exit(ret);
	return (ret);
}
