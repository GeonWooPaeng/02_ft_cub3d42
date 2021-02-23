/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:38:56 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/23 19:14:48 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

#include "mlx.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17

#define TEX_WIDTH 64
#define TEX_HEIGHT 64

#define MAP_WIDTH 24
#define MAP_HEIGHT 24

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
	double		player_position_x;
	double		player_position_y;
	double		direction_vector_x;
	double		direction_vector_y;
	double		plane_x;//카메라 평면X
	double		plane_y;//카메라 평면Y
	void		*mlx;
	void		*win;
	double		move_speed;
	double		rot_speed;
	t_img		img;
	int			buf[SCREEN_HEIGHT][SCREEN_WIDTH];
	int			**texture;
}				t_info;

// map
extern int		world_map[MAP_WIDTH][MAP_HEIGHT];

//key_press
#include "key_press.h"
// void	ft_key_w(int key, t_info *info);
// void	ft_key_s(int key, t_info *info);
// void	ft_key_a(int key, t_info *info);
// void	ft_key_d(int key, t_info *info);
int		key_press(int key, t_info *info);

//map & ray
#include "ft_map.h"
void	ft_side_dist(t_info *info, t_map *map);
void	ft_hit_side(t_info *info, t_map *map);
void	ft_draw(t_map *map);
void	ft_wall(t_info *info, t_map *map);
void	ft_map_init(t_info *info, t_map *map, int x);

//texture
#include "ft_tex.h"
void	ft_tex_x(t_map *map, t_tex *tex);
void	ft_tex_y(t_info *info, t_map *map, t_tex *tex, int x);
void	ft_up_bottom(t_info *info);
#endif