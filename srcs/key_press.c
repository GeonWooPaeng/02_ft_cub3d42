/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:37:25 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/18 21:04:13 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_key_W(t_info *info)
{
	if (!worldMap[(int)(info->playerPositionX + info->directionVectorX * info->moveSpeed)][(int)(info->playerPositionY)])
		info->playerPositionX += info->directionVectorX * info->moveSpeed;
	if (!worldMap[(int)(info->playerPositionX)][(int)(info->playerPositionY + info->directionVectorY * info->moveSpeed)])
		info->playerPositionY += info->directionVectorY * info->moveSpeed;
}

void	ft_key_S(t_info *info)
{
	if (!worldMap[(int)(info->playerPositionX - info->directionVectorX * info->moveSpeed)][(int)(info->playerPositionY)])
		info->playerPositionX -= info->directionVectorX * info->moveSpeed;
	if (!worldMap[(int)(info->playerPositionX)][(int)(info->playerPositionY - info->directionVectorY * info->moveSpeed)])
		info->playerPositionY -= info->directionVectorY * info->moveSpeed;
}

void	ft_key_A(t_info *info)
{
	double oldDirectionX = info->directionVectorX;
	info->directionVectorX = info->directionVectorX * cos(info->rotSpeed) - info->directionVectorY * sin(info->rotSpeed);
	info->directionVectorY = oldDirectionX * sin(info->rotSpeed) + info->directionVectorY * cos(info->rotSpeed);
	double oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
	info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
}

void	ft_key_D(t_info *info)
{
	double oldDirectionX = info->directionVectorX;
	info->directionVectorX = info->directionVectorX * cos(-info->rotSpeed) - info->directionVectorY * sin(-info->rotSpeed);
	info->directionVectorY = oldDirectionX * sin(-info->rotSpeed) + info->directionVectorY * cos(-info->rotSpeed);
	double oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
	info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
}

int		key_press(int key, t_info *info)
{
	if (key == KEY_W)
		ft_key_W(info);
	if (key == KEY_S)
		ft_key_S(info);
	if (key == KEY_A)
		ft_key_A(info);
	if (key == KEY_D)
		ft_key_D(info);
	if (key == K_ESC)
		exit(0);
	return (0);
}
