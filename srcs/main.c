/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:58:25 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/23 20:22:23 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "mlx.h"
// #include <math.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define KEY_W 119
// #define KEY_A 97
// #define KEY_S 115
// #define KEY_D 100

// #define K_ESC 65307

// #define MAP_WIDTH 24
// #define MAP_HEIGHT 24
// #define SCREEN_WIDTH 640
// #define SCREEN_HEIGHT 480

// #define X_EVENT_KEY_PRESS 2
// #define X_EVENT_KEY_EXIT 17

// typedef struct	s_info
// {
// 	double		player_position_x;
// 	double		player_position_y;
// 	double		direction_vector_x;
// 	double		direction_vector_y;
// 	double		plane_x;
// 	double		plane_y;
// 	void		*mlx;
// 	void		*win;
// 	double		move_speed;
// 	double		rot_speed;
// }				t_info;

// int world_map[MAP_WIDTH][MAP_HEIGHT] =
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}	
// };

// void verLine(t_info *info, int x, int y1, int y2, int color)
// {//수직선 그려주기
// 	int tmp;

// 	tmp = y1;
// 	while (tmp <= y2)
// 	{
// 		mlx_pixel_put(info->mlx, info->win, x, tmp, color);
// 		//기본적으로 window에 그리기
// 		//지정된 color로 window의 (x,y)좌표에 픽셀을 그림
// 		tmp++;
// 	}
// }

// int main_loop(t_info *info)
// {
// 	//현재 프레임 시간
// 	// double time = 0;
// 	// 이전 프레임 시간 
// 	// 현재 프레임 시간 - 이전 프레임 시간 = 이동거리 결정 및 fps 측정
// 	// double oldTime = 0;

// 	// 화면 생성후 게임 루프 시작
// 	// while 문은 전체 프레임을 그려내고 입력을 읽는 역할
// 	int x;

// 	x = 0;
// 	while (x < SCREEN_WIDTH)
// 	{
// 		/*
// 		player_position_x,Y: 광선의 시작점
// 		direction_vector_x,Y: 플레이어의 초기 방향 벡터
// 		plane_x,Y: 카메라 평면
// 		아래 for문은 ray의 위치(position), 방향(direction)계산
// 		*/

// 		//cameraX는 for문의 x값이 카메라 평면 상에 있을 때의 x좌표
// 		double cameraX = (2 * x / (double)(SCREEN_WIDTH)) - 1;
// 		// cameraPlaneX == 0; cameraPlaneY == 0.66; dirVecX = -1, dirVecY = 0;
// 		// 광선의 방향은 방향벡터 + 카메라 평면 * 배수
// 		double ray_direction_x = info->direction_vector_x + info->plane_x * cameraX;
// 		double ray_direction_y = info->direction_vector_y + info->plane_y * cameraX;

// 		//DDA Algorithm
// 		//현재 player가 위치한 맵 내 위치(which box of the map)
// 		int map_x = (int)(info->player_position_x);
// 		int map_y = (int)(info->player_position_y);

// 		//현재 위치에서 다음 x사이드 또는 y사이드까지의 거리
// 		double side_dist_x; // 첫번째 x면
// 		double side_dist_y; // 첫번째 y면

// 		//delta_dist_x: 첫번째 x면에서 그 다음 x면까지의 광선의 이동거리
// 		//x는 1만큼 이동
// 		double delta_dist_x = fabs(1 / ray_direction_x);
// 		//delta_dist_y: 첫번째 y면에서 그 다음 y면까지의 광선의 이동거리
// 		//y는 1만큼 이동
// 		double delta_dist_y = fabs(1 / ray_direction_y);

// 		//광선의 이동거리 계산할때 사용할 변수
// 		double perp_wall_dist;

// 		//DDA Algorithm은 반복문을 실행할 때마다 x,y방향으로 한 칸씩 점프
// 		//광선의 방향에 따라 어느 방향으로 건너뛰는지 달라짐
// 		// 그 정보는 step_x, Y에 +1, -1 둘 중 하나로 저장됨
// 		int step_x;
// 		int step_y;

// 		/*
// 		hit: 벽과 부딪혔는지 판별하기 위한 변수
// 		부딪힌다면 루프를 종료
// 		if 부딪혔는데 그게 
// 		x면에 부딪힌 것이면 side = 0
// 		y면에 부딪힌 것이면 side = 1
// 		x면,y면은 어떤 칸의 경계가 되는 선을 의미
// 		*/

// 		int hit = 0;
// 		int side;

// 		// step_x,Y, side_dist_x,Y에 값을 넣어주는 부분
// 		if (ray_direction_x < 0)
// 		{// player 기준 왼쪽각
// 			step_x = -1;
// 			side_dist_x = (info->player_position_x - map_x) * delta_dist_x;
// 			//side_dist_x: 광선의 오른쪽으로 이동하다 처음 만나는 x면까지의 거리
// 		}
// 		else
// 		{//player 기준 오른쪽 각
// 			step_x = 1;
// 			side_dist_x = (map_x + 1.0 - info->player_position_x) * delta_dist_x;
// 		}
// 		if (ray_direction_y < 0)
// 		{
// 			step_y = -1;
// 			side_dist_y = (info->player_position_y - map_y) * delta_dist_y;
// 		}
// 		else
// 		{
// 			step_y = 1;
// 			side_dist_y = (map_y + 1.0 - info->player_position_y) * delta_dist_y;
// 		}

// 		//DDA Algorithm 시작
// 		//아래 while 문은 '벽에 부딪힐 때까지' 매번 한 칸씩 광선 이동
// 		// 반복할 때마다 x방향으로 한 칸 또는 y방향으로 한칸 이동
// 		//if 광선 방향이 x축 방향과 완전히 일치한다면, x방향으로만 한 칸 이동
// 		while (hit == 0)
// 		{
// 			//다음 map 박스로 이동하거나 x,y 방향 둘 중 하나로 이동한다.
// 			if (side_dist_x < side_dist_y)
// 			{
// 				side_dist_x += delta_dist_x;
// 				map_x += step_x; //step_x는 1, -1중 하나
// 				side = 0; // x면에 부딪혔으면 side == 0
// 			}
// 			else
// 			{
// 				side_dist_y += delta_dist_y;
// 				map_y += step_y; //step_y는 1, -1중 하나
// 				side = 1; //y면에 부딪혔으면 side == 1
// 			}
// 			//ray가 벽에 만났는지 확인하는 곳
// 			if (world_map[map_x][map_y] > 0)
// 				hit = 1;
// 		}

// 		/*
// 		광선의 시작점에서 벽까지의 이동거리를 계산하는 부분 => 벽의 높이를 계산하는데 사용
// 		fisheye effect 방지
// 		*/
// 		if (side == 0)
// 			perp_wall_dist = (map_x - info->player_position_x + (1 - step_x) / 2) / ray_direction_x;
// 		else
// 			perp_wall_dist = (map_y - info->player_position_y + (1 - step_y) / 2) / ray_direction_y;

// 		// 스크린에 그릴 line의 높이 계산
// 		int lineHeight = (int)(SCREEN_HEIGHT / perp_wall_dist);
		
// 		// 벽의 범위(0 ~ SCREEN_HEIGHT)
// 		int draw_start = (-lineHeight / 2) + (SCREEN_HEIGHT / 2);
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		int draw_end = (lineHeight / 2) + (SCREEN_HEIGHT / 2);
// 		if (draw_end >= SCREEN_HEIGHT)
// 			draw_end = SCREEN_HEIGHT - 1;

// 		int color;
// 		if (world_map[map_x][map_y] == 1)
// 			color = 0xFF0000;
// 		else if (world_map[map_x][map_y] == 2)
// 			color = 0x00FF00;
// 		else if (world_map[map_x][map_y] == 3)
// 			color = 0x0000FF;
// 		else if (world_map[map_x][map_y] == 4)
// 			color = 0xFFFFFF;
// 		else
// 			color = 0x123145;

// 		//x,y side의 밝기를 달리해준다.
// 		if (side == 1)
// 			color = color / 2;
// 		/*
// 		veLine(): 세로 줄을 긋는다.
// 		x좌표에서 draw_start ~ drawEnd까지 color 색으로 픽셀을 그린다.
// 		(x, draw_start) ~ (x, draw_end)까지 color
// 		x가 점점 증가하면
// 		*/
// 		verLine(info, x, draw_start, draw_end, color);
// 		x++;
// 	}
// 	return (0);
// }

// int key_press(int key, t_info *info)
// {
// 	//WS
//     if (key == KEY_W)
//     {
//         if (!world_map[(int)(info->player_position_x + info->direction_vector_x * info->move_speed)][(int)(info->player_position_y)])
//             info->player_position_x += info->direction_vector_x * info->move_speed;
//         if (!world_map[(int)(info->player_position_x)][(int)(info->player_position_y + info->direction_vector_y * info->move_speed)])
//             info->player_position_y += info->direction_vector_y * info->move_speed;
//     }
// 	if (key == KEY_S)
// 	{
// 		/*
// 		S키: 뒤로 이동
// 		이때, 이동하고자 하는 위치는 맵 상에서 무조건 0이다.
// 		=> 통과할 수 없는 장애물이 있기 때문
// 		*/
//         if (!world_map[(int)(info->player_position_x - info->direction_vector_x * info->move_speed)][(int)(info->player_position_y)])
//             info->player_position_x -= info->direction_vector_x * info->move_speed;
//         if (!world_map[(int)(info->player_position_x)][(int)(info->player_position_y - info->direction_vector_y * info->move_speed)])
//             info->player_position_y -= info->direction_vector_y * info->move_speed;
// 	}
// 	//AD
// 	if (key == KEY_A)
// 	{
//         double oldDirectionX = info->direction_vector_x;
//         info->direction_vector_x = info->direction_vector_x * cos(info->rot_speed) - info->direction_vector_y * sin(info->rot_speed);
//         info->direction_vector_y = oldDirectionX * sin(info->rot_speed) + info->direction_vector_y * cos(info->rot_speed);
//         double oldPlaneX = info->plane_x;
//         info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
//         info->plane_y = oldPlaneX * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
// 	}
// 	if (key == KEY_D)
// 	{
//         double oldDirectionX = info->direction_vector_x;
//         info->direction_vector_x = info->direction_vector_x * cos(-info->rot_speed) - info->direction_vector_y * sin(-info->rot_speed);
//         info->direction_vector_y = oldDirectionX * sin(-info->rot_speed) + info->direction_vector_y * cos(-info->rot_speed);
//         double oldPlaneX = info->plane_x;
//         info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
//         info->plane_y = oldPlaneX * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
//     }
// 	if (key == K_ESC)
// 		exit(0);
// 	return (0);
// }

// int main()
// {
// 	t_info info;
// 	info.mlx = mlx_init();

// 	//info는 아래 필드 모두를 가지고 있다.
// 	info.player_position_x = 12;
// 	info.player_position_y = 5;
// 	info.direction_vector_x = -1;
// 	info.direction_vector_y = 0;
// 	info.plane_x = 0;
// 	info.plane_y = 0.66;
// 	info.move_speed = 0.05;
// 	info.rot_speed = 0.05;

// 	//창을 띄움
// 	info.win = mlx_new_window(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
// 	mlx_loop_hook(info.mlx, &main_loop, &info);
// 	//key_press에 대한 이벤트
// 	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &info);

// 	mlx_loop(info.mlx);
// }






// ------------------------------
// ------------------------------
// ------------------------------
// ------------------------------







// #include "mlx.h"
// #include <math.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define KEY_W 119
// #define KEY_A 97
// #define KEY_S 115
// #define KEY_D 100

// #define K_ESC 65307

// #define MAP_WIDTH 24
// #define MAP_HEIGHT 24
// #define SCREEN_WIDTH 640
// #define SCREEN_HEIGHT 480

// #define X_EVENT_KEY_PRESS 2
// #define X_EVENT_KEY_EXIT 17

// /*
// verLine()대신에 2차원 buffer을 이용해서 한번에 화면에 출력
// TEX_WIDTH: 텍스쳐의 너비
// TEX_HEIGHT: 텍스처의 높이
// */

// #define TEX_WIDTH 64
// #define TEX_HEIGHT 64

// //get_img_data_addr 함수에서 쓸 변수를 갖고 있는 구조체
// typedef struct	s_img
// {
// 	void		*img;
// 	int			*data;
// 	int			size_l;
// 	int			bit_per_pixel;
// 	int			endian;
// }				t_img;

// typedef struct	s_info
// {
// 	double		player_position_x;
// 	double		player_position_y;
// 	double		direction_vector_x;
// 	double		direction_vector_y;
// 	double		plane_x;
// 	double		plane_y;
// 	void		*mlx;
// 	void		*win;
// 	double		move_speed;
// 	double		rot_speed;

// 	// testured에서 변수 추가
// 	t_img		img;
// 	int			**buf;
// 	int			texture[8][TEX_HEIGHT * TEX_WIDTH];
// }				t_info;

// int	calculateAndSaveToMap(t_info *info);
// void image_draw(t_info *info);

// // textured 에서 변경된 map, 요소 추가
// int		world_map[MAP_WIDTH][MAP_HEIGHT] =
// {
// 	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
// 	{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
// 	{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
// 	{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
// 	{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
// 	{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
// 	{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
// 	{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
// 	{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
// 	{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
// 	{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
// 	{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
// 	{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
// 	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
// 	{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
// 	{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
// 	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
// 	{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
// 	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
// 	{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
// 	{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
// 	{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
// 	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
// 	{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
// };

// int main_loop(t_info *info)
// {
// 	calculateAndSaveToMap(info);
// 	image_draw(info);

// 	//warning 방지
// 	return (0);
// }

// void image_draw(t_info *info)
// {
// 	for (int y = 0; y < SCREEN_HEIGHT; y++)
// 		for (int x = 0; x < SCREEN_WIDTH; x++)
// 			info->img.data[y * SCREEN_WIDTH + x] = info->buf[y][x];
	
// 	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
// }

// int calculateAndSaveToMap(t_info *info)
// {
// 	//화면 생성 후 게임 루프 시작
// 	//while문은 전체 프레임을 그려내고 입력을 읽는 역할을 한다.
// 	int x;

// 	x = 0;
// 	while (x < SCREEN_WIDTH)
// 	{
// 		double cameraX = (2 * x / (double)(SCREEN_WIDTH)) - 1;

// 		double ray_direction_x = info->direction_vector_x + info->plane_x * cameraX;
// 		double ray_direction_y = info->direction_vector_y + info->plane_y * cameraX;

// 		int map_x = (int)(info->player_position_x);
// 		int map_y = (int)(info->player_position_y);

// 		double side_dist_x;
// 		double side_dist_y;

// 		double delta_dist_x = fabs(1 / ray_direction_x);
// 		double delta_dist_y = fabs(1 / ray_direction_y);

// 		//광선의 이동거리를 계산할 때 사용할 변수
// 		double perp_wall_dist;

// 		int step_x;
// 		int step_y;

// 		int hit = 0;
// 		int side;

// 		if (ray_direction_x < 0)
// 		{
// 			step_x = -1;
// 			side_dist_x = (info->player_position_x - map_x) * delta_dist_x;
// 		}
// 		else
// 		{
// 			step_x = 1;
// 			side_dist_x = (map_x + 1.0 - info->player_position_x) * delta_dist_x;
// 		}
// 		if (ray_direction_y < 0)
// 		{
// 			step_y = -1;
// 			side_dist_y = (info->player_position_y - map_y) * delta_dist_y;
// 		}
// 		else
// 		{
// 			step_y = 1;
// 			side_dist_y = (map_y + 1.0 - info->player_position_y) * delta_dist_y;
// 		}

// 		while (hit == 0)
// 		{
// 			if (side_dist_x < side_dist_y)
// 			{
// 				side_dist_x += delta_dist_x;
// 				map_x += step_x; //step_x: 1, -1
// 				side = 0; //x면에 부딪힌 것
// 			}
// 			else
// 			{
// 				side_dist_y += delta_dist_y;
// 				map_y += step_y; //step_y: 1, -1
// 				side = 1;
// 			}
// 			if (world_map[map_x][map_y] > 0)
// 				hit = 1;
// 		}
// 		if (side == 0)
// 			perp_wall_dist = (map_x - info->player_position_x + (1 - step_x) / 2) / ray_direction_x;
// 		else
// 			perp_wall_dist = (map_y - info->player_position_y + (1 - step_y) / 2) / ray_direction_y;

// 		int lineHeight = (int)(SCREEN_HEIGHT / perp_wall_dist);

// 		int draw_start = (-lineHeight / 2) + (SCREEN_HEIGHT / 2);
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		int draw_end = (lineHeight / 2) + (SCREEN_HEIGHT / 2);
// 		if (draw_end >= SCREEN_HEIGHT)
// 			draw_end = SCREEN_HEIGHT - 1;

// 		// texturing calculation 
// 		// 1을 빼주는 이유: 0번째 텍스쳐도 0, 벽이 없어도 0이기 때문
// 		// 1을 안빼주면 시작하자마자 뒷방향으로 이동하면 segmentation fault
// 		int tex_num = world_map[map_x][map_y] - 1;
		
// 		//wallX의 값: 벽의 x면과 부딪힌 경우(side == 0), 텍스처의 x좌표에 대해서만 사용
// 		// 벽의 Y좌표가 된다.
// 		double wall_x;
// 		if (side == 0)
// 			wall_x = info->player_position_y + perp_wall_dist * ray_direction_y;
// 		else
// 			wall_x = info->player_position_x + perp_wall_dist * ray_direction_x;
// 		wall_x -= floor(wall_x);

// 		//tex_x는 texture의 x좌표를 나타낸다.
// 		// x coordinate on the texture
// 		int tex_x = (int)(wall_x * (double)TEX_WIDTH);
// 		if (side == 0 && ray_direction_x > 0)
// 			tex_x = TEX_WIDTH - tex_x - 1;
// 		if (side == 1 && ray_direction_y < 0)
// 			tex_x = TEX_WIDTH - tex_x - 1;
		
// 		/*
// 		tex_y를 지정하는 부분
// 		step은 스크린 픽셀당 texture 좌표를 얼마나 증가시켜줄 건지 결정
// 		buffer[y][x]에 넣을 color은 texture 배열에서 가져온다.
// 		*/
// 		double step = 1.0 * TEX_HEIGHT / lineHeight;
// 		double tex_pos = (draw_start - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;
// 		for (int y = draw_start; y < draw_end; y++)
// 		{
// 			int tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
// 			tex_pos += step;
// 			int color = info->texture[tex_num][TEX_HEIGHT * tex_y + tex_x];
// 			//광선이 벽의 y면에 부딪힌 경우(side == 1)
// 			//조명 표현을 위해 색상을 검게 만든다.
// 			//이진수를 2로 나눠 RGB값을 반감시킨다.
// 			if (side == 1)
// 				color = (color >> 1) & 8355711;
// 			info->buf[y][x] = color;
// 		}
// 		x++;
// 	}
// 	return (0);
// }

// int key_press(int key, t_info *info)
// {
//     // WS
//     if (key == KEY_W)
//     {
//         if (!world_map[(int)(info->player_position_x + info->direction_vector_x * info->move_speed)][(int)(info->player_position_y)])
//             info->player_position_x += info->direction_vector_x * info->move_speed;
//         if (!world_map[(int)(info->player_position_x)][(int)(info->player_position_y + info->direction_vector_y * info->move_speed)])
//             info->player_position_y += info->direction_vector_y * info->move_speed;
//     }

//     if (key == KEY_S)
//     {
//         if (!world_map[(int)(info->player_position_x - info->direction_vector_x * info->move_speed)][(int)(info->player_position_y)])
//             info->player_position_x -= info->direction_vector_x * info->move_speed;
//         if (!world_map[(int)(info->player_position_x)][(int)(info->player_position_y - info->direction_vector_y * info->move_speed)])
//             info->player_position_y -= info->direction_vector_y * info->move_speed;
//     }

//    // AD
//     if (key == KEY_A)
//     {
//         double oldDirectionX = info->direction_vector_x;
//         info->direction_vector_x = info->direction_vector_x * cos(info->rot_speed) - info->direction_vector_y * sin(info->rot_speed);
//         info->direction_vector_y = oldDirectionX * sin(info->rot_speed) + info->direction_vector_y * cos(info->rot_speed);
//         double oldPlaneX = info->plane_x;
//         info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
//         info->plane_y = oldPlaneX * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
//     }

//     if (key == KEY_D)
//     {
//         double oldDirectionX = info->direction_vector_x;
//         info->direction_vector_x = info->direction_vector_x * cos(-info->rot_speed) - info->direction_vector_y * sin(-info->rot_speed);
//         info->direction_vector_y = oldDirectionX * sin(-info->rot_speed) + info->direction_vector_y * cos(-info->rot_speed);
//         double oldPlaneX = info->plane_x;
//         info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
//         info->plane_y = oldPlaneX * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
//     }
//     if (key == K_ESC)
//         exit(0);
//     return (0);
// }

// int main()
// {
// 	t_info info;
// 	info.mlx = mlx_init();

// 	info.player_position_x = 12;
// 	info.player_position_y = 5;
// 	info.direction_vector_x = -1;
// 	info.direction_vector_y = 0;
// 	info.plane_x = 0;
// 	info.plane_y = 0.66;
// 	info.move_speed = 0.05;
// 	info.rot_speed = 0.05;

// 	/*
// 	buffer 초기화
// 	buffer: 우리가 띄운 창의 크기와 같다.
// 	x->SCREEN_WIDTH로 가면서 화면을 그려내기 때문에
// 	y값이 buffer의 앞에 온다(info.buf[y][x])
// 	*/
// 	info.buf = (int **)malloc(sizeof(int *) * SCREEN_HEIGHT);
// 	for (int i = 0; i < SCREEN_HEIGHT; i++)
// 		info.buf[i] = (int *)malloc(sizeof(int) * SCREEN_WIDTH);
	
// 	for (int i = 0; i < SCREEN_HEIGHT; i++)
// 		for (int j = 0; j < SCREEN_WIDTH; j++)
// 			info.buf[i][j] = 0;

// 	/*
// 	info.texture 변수는 다음과 같이 선언되어 있다.
// 	int texture[8][TEX_HEIGHT * TEX_WIDTH];
// 	이것은 총 8가지 종류의 texture을 저장할 수 있고, 그 크기가 TEX_HEIGHT * TEX_WIDTH이다.
// 	*/
// 	for (int i = 0; i < 8; i++)
// 		for (int j = 0; j < TEX_HEIGHT * TEX_WIDTH; j++)
// 			info.texture[i][j] = 0;

// 	/*
// 	texture를 생성
// 	(bit 연산자인)xor color 및 x, xy color를 지정한다.
// 	세가지 값은 각각 xor 패턴, 그라데이션, 벽돌스타일의 패턴을 나타낸다.
// 	*/
// 	for (int x = 0; x < TEX_WIDTH; x++)
// 	{
// 		for (int y = 0; y < TEX_HEIGHT; y++)
// 		{
// 			int xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
// 			int ycolor = y * 256 / TEX_HEIGHT;
// 			int xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
// 			info.texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
// 			info.texture[1][TEX_WIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
// 			info.texture[2][TEX_WIDTH * y + x] = 256 * xycolor + 65536 * xycolor;
// 			info.texture[3][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
// 			info.texture[4][TEX_WIDTH * y + x] = 256 * xorcolor; //xor gree
// 			info.texture[5][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
// 			info.texture[6][TEX_WIDTH * y + x] = 65536 * ycolor; //red gradient
// 			info.texture[7][TEX_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
// 		}
// 	}
// 	//textured에서 추가된 코드
// 	info.win = mlx_new_window(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
// 	info.img.img = mlx_new_image(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bit_per_pixel, &info.img.size_l, &info.img.endian);

// 	mlx_loop_hook(info.mlx, &main_loop, &info);
// 	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &info);
// 	mlx_loop(info.mlx);
// }


// ------------------------------
// ------------------------------
// ------------------------------
// ------------------------------



#include "ft_cub3d.h"


int	calculateAndSaveToMap(t_info *info);
// void	image_draw(t_info *info);

int		world_map[MAP_WIDTH][MAP_HEIGHT] = 
{
	{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
	{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
	{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
	{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
	{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
	{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
	{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
	{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
	{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
	{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
	{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
	{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
	{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
	{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
	{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
	{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
	{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
	{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
	{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
	{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
};

int		main_loop(t_info *info)
{
	calculateAndSaveToMap(info);
	image_draw(info);
	return (0);
}

// void	image_draw(t_info *info)
// {
// 	for (int y = 0; y < SCREEN_HEIGHT; y++)
// 		for (int x = 0; x < SCREEN_WIDTH; x++)
// 			info->img.data[y * SCREEN_WIDTH + x] = info->buf[y][x];

// 	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
// }

int calculateAndSaveToMap(t_info *info)
{
	// /*
	// 나중에 화면에 옹릴 buf의 위에서 붜 아래로, 아래서부터 위로 다른 색상을 칠해준다.
	// bottom, up color
	// -----------------------------------------------------------------
	// */
	// for (int x = 0; x < SCREEN_WIDTH; x++)
	// {
	// 	for (int y = 0; y < SCREEN_HEIGHT; y++)
	// 	{
	// 		info->buf[y][x] = 0xFFFF00; // 바닥
	// 		info->buf[SCREEN_HEIGHT - y - 1][x] = 0x000000; //천장
	// 	}
	// }
	// //화면 생성 후 게임 루프 시작
	// //while문은 전체 프레임을 그려내고 입력을 읽는 역할을 함
	// //---------------------------------------------------------------
	ft_up_bottom(info);
	int x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		t_map *map;
		t_tex *tex;

		map = malloc(sizeof(t_map));
		tex = malloc(sizeof(t_tex));
		ft_map_init(info, map, x);
		ft_side_dist(info, map);
		ft_hit_side(info, map);
		// // cameraX: for문의 x 값이 카메라 평면 상에 있을 때의 x좌표
		// double cameraX = (2 * x / (double)(SCREEN_WIDTH)) - 1;
		// // cameraPlaneX == 0; cameraPlaneY == 0.66; dirVecX = -1; dirVecY = 0;
		// // 광선의 방향은 방향벡터 + 카메라 평면 * 배수
		// double ray_direction_x = info->direction_vector_x + info->plane_x * cameraX;
		// double ray_direction_y = info->direction_vector_y + info->plane_y * cameraX;

		// //DDA Algorithm - cal
		// //현재 player가 위치한 맵 내 위치(which box of the map)
		// int map_x = (int)(info->player_position_x);
		// int map_y = (int)(info->player_position_y);

		// //현재 위치에서 다음 x사이드 또는 y사이드까지의 거리
		// double side_dist_x;
		// double side_dist_y;

		// //delta_dist_x는 첫 번째 x면에서 그 다음 x면까지의 광선의 이동거리
		// //이 상황에서 x는 1만큼 이동
		// double delta_dist_x = fabs(1 / ray_direction_x);
		// //delta_dist_y는 첫 번째 y면에서 그 다음 y면까지의 광선의 이동거리
		// //이 상황에서 y는 1만큼 이동
		// double delta_dist_y = fabs(1 / ray_direction_y);

		// //광선의 이동거리 계산할 때 필요한 변수
		// double perp_wall_dist;

		// //광선의 방향에 따라 어느 방향으로 건너뛰는지 달라진다.
		// int step_x;
		// int step_y;

		// //hit: 벽과 부딪혔는지 판단하는 변수
		// //x면에 부딪혔으면 side = 0;
		// //y면에 부딪혔으면 side = 1;
		// // x면, y면은 어떤 칸의 경계가 되는 선
		// int hit = 0;
		// int side;
		
		// if (ray_direction_x < 0)
		// {
		// 	step_x = -1;
		// 	side_dist_x = (info->player_position_x - map_x) * delta_dist_x;
		// }
		// else
		// {
		// 	step_x = 1;
		// 	side_dist_x = (map_x + 1.0 - info->player_position_x) * delta_dist_x;
		// }
		// if (ray_direction_y < 0)
		// {
		// 	step_y = -1;
		// 	side_dist_y = (info->player_position_y - map_y) * delta_dist_y;
		// }
		// else
		// {
		// 	step_y = 1;
		// 	side_dist_y = (map_y + 1.0 - info->player_position_y) * delta_dist_y;
		// }
		// //벽에 부딪힐 때까지 매번 한 칸씩 광선 이동
		// while (hit == 0)
		// {
		// 	// 다음 map 박스로 이동하거나 x,y 방향 둘 중 하나로 이동
		// 	if (side_dist_x < side_dist_y)
		// 	{
		// 		side_dist_x += delta_dist_x;
		// 		map_x += step_x;
		// 		side = 0;
		// 	}
		// 	else
		// 	{
		// 		side_dist_y += delta_dist_y;
		// 		map_y += step_y;
		// 		side = 1;
		// 	}
		// 	//ray가 벽을 만났는지 확인하는 작업
		// 	if (world_map[map_x][map_y] > 0)
		// 		hit = 1;
		// }

		// // 광선의 시작점에서 벽까지의 이동거리 계산
		// if (side == 0)
		// 	perp_wall_dist = (map_x - info->player_position_x + (1 - step_x) / 2) / ray_direction_x;
		// else
		// 	perp_wall_dist = (map_y - info->player_position_y + (1 - step_y) / 2) / ray_direction_y;
		
		// // 스크린에 그릴 line의 높이 계산
		// int lineHeight = (int)(SCREEN_HEIGHT / perp_wall_dist);
		
		// //선을 그릴 시작점과 끝점 구하기
		// int draw_start = (-lineHeight / 2) + (SCREEN_HEIGHT / 2);
		// if (draw_start < 0)
		// 	draw_start = 0;
		// int draw_end = (lineHeight / 2) + (SCREEN_HEIGHT / 2);
		// if (draw_end >= SCREEN_HEIGHT)
		// 	draw_end = SCREEN_HEIGHT - 1;

		ft_draw(map);
		ft_wall(info, map);
		// // wall_x이 어느 벽에 부딪쳤는지에 따라 값구하기
		// double wall_x;
		// if (side == 0)
		// 	wall_x = info->player_position_y + perp_wall_dist * ray_direction_y;
		// else
		// 	wall_x = info->player_position_x + perp_wall_dist * ray_direction_x;
		// wall_x -= floor(wall_x);

		// // tex 값 계산--------------------------------------------------
		// //texturing calculation
		tex->tex_num = world_map[map->map_x][map->map_y] - 1;
		ft_tex_x(map, tex);
		ft_tex_y(info, map, tex, x);
		// //tex_x는 texture의 x좌표를 나타낸다.
		// int tex_x = (int)(wall_x * (double)TEX_WIDTH);
		// if (side == 0 && ray_direction_x > 0)
		// 	tex_x = TEX_WIDTH - tex_x - 1;
		// if (side == 1 && ray_direction_y < 0)
		// 	tex_x = TEX_WIDTH - tex_x - 1;

		// // tex_y를 지정하는 곳
		// // step: 스크린 픽셀당 texture 좌표를 얼마나 증가시켜줄 건지 결정
		// double step = 1.0 * TEX_HEIGHT / lineHeight;
		// double tex_pos = (draw_start - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;
		// for (int y = draw_start; y < draw_end; y++)
		// {
		// 	int tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		// 	tex_pos += step;
		// 	int color = info->texture[tex_num][TEX_HEIGHT * tex_y + tex_x];
		// 	if (side == 1)
		// 		color = (color >> 1) & 8355711;
		// 	info->buf[y][x] = color;
		// }
		// //----------------------------------------------------------------
		free(map);
		free(tex);
		x++;
	}
	return (0);
}


// void load_image(t_info *info, int *texture, char *path, t_img *img)
// {
// 	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
// 	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
// 	for (int y = 0; y < img->img_height; y++)
// 	{
// 		for (int x = 0; x < img->img_width; x++)
// 		{
// 			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
// 		}
// 	}
// 	mlx_destroy_image(info->mlx, img->img);
// }

// void    load_texture(t_info *info)
// {
// 	t_img    img;

// 	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
// 	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
// 	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
// 	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
// 	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
// 	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
// 	load_image(info, info->texture[6], "textures/wood.xpm", &img);
// 	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
// }

int main()
{
	t_info info;
	info.mlx = mlx_init();

	info.player_position_x = 22.0;
	info.player_position_y = 11.5;
	info.direction_vector_x = -1.0;
	info.direction_vector_y = 0.0;
	info.plane_x = 0.0;
	info.plane_y = 0.66;
	info.move_speed = 0.05;
	info.rot_speed = 0.05;

	if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH))))
			return (-1);
	
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < TEX_HEIGHT * TEX_WIDTH; j++)
			info.texture[i][j] = 0;

	load_texture(&info);

	info.win = mlx_new_window(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	info.img.img = mlx_new_image(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &info);
	mlx_loop(info.mlx);
}
