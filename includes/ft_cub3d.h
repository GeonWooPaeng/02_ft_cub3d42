/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:38:56 by gpaeng            #+#    #+#             */
/*   Updated: 2021/03/11 17:12:49 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef FT_CUB3D_H
// # define FT_CUB3D_H

// #include "mlx.h"
// #include <math.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <unistd.h>


// // #define SCREEN_WIDTH 640
// // #define SCREEN_HEIGHT 480

// #define X_EVENT_KEY_PRESS 2
// #define X_EVENT_KEY_EXIT 17

// #define TEX_WIDTH 64
// #define TEX_HEIGHT 64

// #define MAP_WIDTH 24
// #define MAP_HEIGHT 24

// //get_img_data_addr 함수에서 쓸 변수를 갖고 있는 구조체
// typedef struct	s_img
// {
// 	void		*img;
// 	int			*data;
// 	int			size_l;
// 	int			bpp;
// 	int			endian;
// 	int			img_width;
// 	int			img_height;
// }				t_img;

// typedef struct	s_info
// {
// 	double		player_position_x;
// 	double		player_position_y;
// 	double		direction_vector_x;
// 	double		direction_vector_y;
// 	double		plane_x; //카메라 평면X
// 	double		plane_y; //카메라 평면Y
// 	void		*mlx;
// 	void		*win;
// 	int			win_width;
// 	int			win_height;
// 	int			floor_color;
// 	int			ceiling_color;
// 	int			map_width;
// 	int			map_height;
// 	double		move_speed;
// 	double		rot_speed;
// 	t_img		img;
// 	// int			buf[SCREEN_HEIGHT][SCREEN_WIDTH];
// 	int			**texture;
// 	char		**tab;
// }				t_info;

// // map
// // extern int		world_map[MAP_WIDTH][MAP_HEIGHT];



// //setting 
// #include "ft_img.h"
// void			image_draw(t_info *info);
// void			load_texture(t_info *info);
// void			load_image(t_info *info, int *texture, char *path, t_img *img);

// //key_press
// #include "key_press.h"
// // void	ft_key_w(int key, t_info *info);
// // void	ft_key_s(int key, t_info *info);
// // void	ft_key_a(int key, t_info *info);
// // void	ft_key_d(int key, t_info *info);
// int				key_press(int key, t_info *info);

// //map & ray
// #include "ft_map.h"
// void			ft_side_dist(t_info *info, t_map *map);
// void			ft_hit_side(t_info *info, t_map *map);
// void			ft_draw(t_info *info, t_map *map);
// void			ft_wall(t_info *info, t_map *map);
// void			ft_map_init(t_info *info, t_map *map, int x);

// //texture
// #include "ft_tex.h"
// void			ft_tex_x(t_map *map, t_tex *tex);
// void			ft_tex_y(t_info *info, t_map *map, t_tex *tex, int x);
// void			ft_up_bottom(t_info *info);

// typedef struct	s_all
// {
// 	t_info		info;
// 	t_img		img;
// 	t_map		map;
// 	t_tex		tex;
// }				t_all;

// //parsing 
// size_t			ft_strlen(const char *str);
// char			*ft_strndup(const char *str, size_t num);
// char			*ft_strjoin(const char *a, const char *b);
// char			*ft_strchr(const char *str, int c);
// int				ft_make_arr(char **arr, char *buf, ssize_t nr);
// char			*ft_make_line(char **arr, int *check);
// int				get_next_line(int fd, char **line);
// int				ft_color(t_all *all, char *line, int *i);
// int				ft_check_line(t_all *all, char *line);
// int				ft_parse(t_all *all, char *cub);
// int				ft_isspace(char *line, int *i);
// int				ft_atoi(char *line, int *i);
// int				ft_resolution(t_all *all, char *line, int *i);
// int				ft_texture(t_all *all, char *line, int *i, int *idx);
// int				ft_map(t_all *all, char *line, int *i);

// #endif

// --------------------------------------

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

#include "mlx.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct		s_info
{
	void			*mlx;
	void			*win;
	int				win_x; //width
	int				win_y; //height
}					t_info;

typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				draw_start; // 선을 그릴 시작점
	int				draw_end;
	int				**texture; //img.data를 color로 바꾸기 위해 변경해주는 곳
	int				**buf; //texture을 color로 변화시켜 저장한 곳
	int				fsh;
}					t_img;

typedef struct		s_map
{
	char			**tab;
	int				x; //map_x: 현재 player가 위치한 맵 내 위치
	int				y; 
	int				plane;
}					t_map;

typedef struct		s_tex
{
	unsigned int	*n;
	unsigned int	*s;
	unsigned int	*e;
	unsigned int	*w;
	int				x; //tex_x: texture의 x좌표
	int				y;
	int				tex_num; //texturing
	unsigned int	floor_color;
	unsigned int	ceiling_color;
}					t_tex;

typedef struct		s_pos //player position
{
	double			x;
	double			y;
	double			side_dist_x; // 격자와의 교점까지의 거리
	double			side_dist_y; // 현재 위치에서 다음 사이드 까지의 거리(플레이어 위치 부터 다음 번 격자)
}					t_pos;

typedef struct		s_dir
{
	double			x; //direction vector
	double			y;
	double			a;
}					t_dir;

typedef struct		s_ray
{
	double			x; //ray-direction
	double			y;
	double			perp_wall_dist; //광선의 이동거리를 계산할 떄 필요한 변수
	double			delta_dist_x; //다음 X 까지의 광선의 이동거리
	double			delta_dist_y;
	double			wall_x; // 광선의 시작점에서 벽까지의 이동거리
	int				step_x; //어느 방향으로 건너 뛰는가
	int				step_y; //map.y의 초기값을 정한다.
	int				i;
}					t_ray;

typedef struct		s_hit
{
	double			x;
	double			y;
	double			d;
	int				h; //벽과 부딪혔는지 판별하기 위한 변수
	int				side; //어느 면에 부딪혔는지 파악(x == 0, y == 1)
}					t_hit;

typedef struct		s_plane //spr
{
	double			x;
	double			y;
	double			d;
}					t_plane;

typedef struct		s_all
{
	t_info			info;
	t_img			img;
	t_map			map;
	t_pos			pos;
	t_dir			dir;
	t_ray			ray;
	t_hit			hit;
	t_plane			plane;
	t_tex			tex;
}					t_all;


//parsing 
size_t				ft_strlen(const char *str);
char				*ft_strndup(const char *str, size_t num);
char				*ft_strjoin(const char *a, const char *b);
char				*ft_strchr(const char *str, int c);
int					ft_make_arr(char **arr, char *buf, ssize_t nr);
char				*ft_make_line(char **arr, int *check);
int					get_next_line(int fd, char **line);
int					ft_color(t_all *all, char *line, int *i);
int					ft_check_line(t_all *all, char *line);
int					ft_parsing(t_all *all, char *cub);
int					ft_isspace(char *line, int *i);
int					ft_atoi(char *line, int *i);
int					ft_resolution(t_all *all, char *line, int *i);
int					ft_texture(t_all *all, char *line, int *i, int *idx);
int					ft_map(t_all *all, char *line, int *i);
int					ft_check_name(char *a, char *b);

//key_press
#include "key_press.h"
// void	ft_key_w(int key, t_info *info);
// void	ft_key_s(int key, t_info *info);
// void	ft_key_a(int key, t_info *info);
// void	ft_key_d(int key, t_info *info);
int					key_press(int key, t_info *info);

#endif