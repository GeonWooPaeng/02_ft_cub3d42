/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:10:08 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/23 20:21:41 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMG_H
# define FT_IMG_H

#include "ft_cub3d.h"

void	image_draw(t_info *info);
void	load_texture(t_info *info);
void	load_image(t_info *info, int *texture, char *path, t_img *img);

#endif