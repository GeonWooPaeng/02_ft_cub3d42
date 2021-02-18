/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:24:59 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/18 17:16:07 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_PRESS_H
# define KEY_PRESS_H

#include "ft_cub3d.h"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define K_ESC 65307

void	ft_key_W(t_info *info);
void	ft_key_S(t_info *info);
void	ft_key_A(t_info *info);
void	ft_key_D(t_info *info);
int		key_press(int key, t_info *info);

#endif