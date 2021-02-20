/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:38:56 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/18 20:52:26 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

#include "mlx.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define screenWidth 640
#define screenHeight 480

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17

#define texWidth 64
#define texHeight 64

#define mapWidth 24
#define mapHeight 24

//get_img_data_addr 함수에서 쓸 변수를 갖고 있는 구조체
typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_info
{
	double		playerPositionX;
	double		playerPositionY;
	double		directionVectorX;
	double		directionVectorY;
	double		planeX;//카메라 평면X
	double		planeY;//카메라 평면Y
	void		*mlx;
	void		*win;
	double		moveSpeed;
	double		rotSpeed;
	t_img		img;
	int			buf[screenHeight][screenWidth];
	int			**texture;
}				t_info;

// map
extern int		worldMap[mapWidth][mapHeight];

//key_press
#include "key_press.h"
// void	ft_key_W(int key, t_info *info);
// void	ft_key_S(int key, t_info *info);
// void	ft_key_A(int key, t_info *info);
// void	ft_key_D(int key, t_info *info);
int		key_press(int key, t_info *info);


#endif