/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:38:56 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/18 17:32:31 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include "mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define PI 3.1415926535897

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
 
# define NORTH 3
# define EAST 4
# define SOUTH 5
# define WEST 6
# define SPRITE 7
# define FLOOR 8
# define CEILING 9
# define COLOR 10
# define W_SIZE 11


typedef struct		s_info
{
	void			*mlx;
	void			*win;
	int				win_x; //width
	int				win_y; //height
	int				error_n; //error check
	int				sprite_num;
	// int				dir;
}					t_info;

typedef struct		s_img
{
	void			*ptr;
	int				*data; //adr
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
	// int				fsh;
}					t_img;

typedef struct		s_map
{
	char			**tab;
	char			**visited;
	int				x; //map_x: 현재 player가 위치한 맵 내 위치
	int				y;
	int				width;
	int				height;
}					t_map;

typedef struct		s_tex
{
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
	char			*sprite_texture;
	int				**texture; //img.data를 color로 바꾸기 위해 변경해주는 곳
	int				**buf; //texture을 color로 변화시켜 저장한 곳
	double			*zbuf; //sprite의 수직 줄무늬의 벽까지의 거리
	int				x; //tex_x: texture의 x좌표
	int				y;
	int				tex_num; //texturing
	int				floor_color;
	int				ceiling_color;
	double			step; //스크린 픽셀당 texture 좌표를 얼마나 증가시켜줄 것인가.
	double			tex_pos;
}					t_tex;

typedef struct		s_player //player position
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	int				dir;
}					t_player;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			distance;
}					t_sprite;

typedef struct		s_sprite_ray
{
	double			x;
	double			y;
	double			inv_det; //inversion_detection
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				height;
	int				width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	
}					t_sprite_ray;

typedef struct		s_sprite_tex
{
	int				x;
	int				y;
}					t_sprite_tex;

typedef struct		s_dir
{
	double			x; //direction vector
	double			y;
	double			a;
}					t_dir;

typedef struct		s_ray
{
	double			camera_x;
	double			dir_x; //ray-direction
	double			dir_y; //광선의 방향 = 방향 벡터 + 카메라 평면 * 배수
	double			perp_wall_dist; //광선의 이동거리를 계산할 떄 필요한 변수 , 광선이 x방향으로 몇칸이나 지나갔는지를 나타내는 수 / rayDirX;
	double			delta_dist_x; //다음 X 까지의 광선의 이동거리
	double			delta_dist_y;
	double			side_dist_x; // 격자와의 교점까지의 거리
	double			side_dist_y; // 현재 위치에서 다음 사이드 까지의 거리(플레이어 위치 부터 다음 번 격자)
	double			wall_x; // 광선의 시작점에서 벽까지의 이동거리
	int				step_x; //어느 방향으로 건너 뛰는가
	int				step_y; //map.y의 초기값을 정한다.
	int				line_height; //스크린에 그릴 line height
	int				draw_start; // 선을 그릴 시작점
	int				draw_end;
	int				i;
}					t_ray;

typedef struct		s_hit
{
	double			x;
	double			y;
	int				h; //벽과 부딪혔는지 판별하기 위한 변수
	int				side; //어느 면에 부딪혔는지 파악(x == 0, y == 1)
}					t_hit;

// typedef struct		s_flag
// {
// 	int				cnt;
// 	int				r;
// 	int				no;
// 	int				so;
// 	int				we;
// 	int				ea;
// 	int				s;
// 	int				f;
// 	int				c;
// }					t_flag;

typedef struct		s_all
{
	t_info			info;
	t_img			img;
	t_map			map;
	t_player		player;
	t_dir			dir;
	t_ray			ray;
	t_hit			hit;
	t_tex			tex;
	// t_flag			flag;
	t_sprite		*sprite;
	t_sprite_ray	sprite_ray;
	t_sprite_tex	sprite_tex;
}					t_all;

//ft_init.c
// void				ft_init_flag(t_all *all);
double				ft_init_player_dir(t_all *all);
void				ft_init_player(t_all *all);
void				ft_init_info(t_all *all);
void				ft_init_ray(t_all *all, int x);

//ft_img.c
void				ft_up_bottom(t_all *all);
void				ft_load_texture(t_all *all);
void				load_image(t_all *all, int *file, char *path, t_img *img);
void				ft_image_draw(t_all *all);

//ft_init.img.c
void				ft_init_buffer(t_all *all);
void				ft_init_zbuffer(t_all *all);
int					ft_init_texture(t_all *all);

//parse/*
size_t				ft_strlen(const char *str);
char				*ft_strndup(const char *str, size_t num);
char				*ft_strjoin(const char *a, const char *b);
char				*ft_strchr(const char *str, int c);
int					ft_make_arr(char **arr, char *buf, ssize_t nr);
char				*ft_make_line(char **arr, int *check);
int					get_next_line(int fd, char **line);
int					ft_color(t_all *all, char *line, int *i, int type);
int					ft_check_line(t_all *all, char *line);
int					ft_parsing(t_all *all, char *cub);
int					ft_isspace(char *line, int *i);
int					ft_atoi(char *line, int *i);
int					ft_resolution(t_all *all, char *line, int *i);
int					ft_texture(t_all *all, char *line, int *i, int type);
int					ft_map(t_all *all, char *line, int *i);
void				ft_position(t_all *all);
void				ft_check_texture(t_all *all, char *arr, int type);
// void				ft_check_flag(t_all *all, int type);
int					ft_check_name(char *a, char *b);

//ft_key_press.c
void				ft_move_ws(t_all *all, double speed);
void				ft_move_ad(t_all *all, double speed);
void				ft_rotate_player(t_all *all, double speed);
int					ft_key_press(int key, t_all *all);

//ft_raycasting.c
void				ft_side_dist(t_all *all);
void				ft_hit_side(t_all *all);
void				ft_wall_dist(t_all *all);
void				ft_wall_height(t_all *all);
void				ft_raycasting(t_all *all);

// ft_tex_xy.c
void				ft_wall_texture(t_all *all);
void				ft_wall_color(t_all *all, int x);

//main.c
int					ft_check_name(char *a, char *b);
int					ft_exit(int ret);
void				ft_init_cub3d(t_all *all, char *cub);
int					ft_main_loop(t_all *all);

//ft_sprite_utils.c
void ft_rsort_sprite(t_all *all);
void ft_init_sprite(t_all *all);
void ft_set_sprite(t_all *all);

//ft_sprite.c
void ft_sprite_dist(t_all *all);
void ft_sprite_conversion(t_all *all, int x);
void ft_sprite_hw(t_all *all);
void ft_sprite_color(t_all *all, int sprite);
void ft_sprite(t_all *all);


#endif