/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:26:41 by gpaeng            #+#    #+#             */
/*   Updated: 2021/05/11 16:26:57 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	ft_init_cub3d(t_all *all, char *cub)
{
	ft_init_info(all);
	ft_init_player(all);
	ft_parsing(all, cub);
	ft_rotate_player(all, ft_init_player_dir(all));
	all->info.mlx = mlx_init();
	if(!ft_init_buffer(all))
		ft_error("[Error] init buffer malloc");
	if (!ft_init_zbuffer(all))
		ft_error("[Error] init zbuffer malloc");
	if (!ft_init_texture(all))
		ft_error("[Error] init texture malloc");
}

int		ft_main_loop(t_all *all)
{
	ft_raycasting(all);
	ft_sprite(all);
	ft_image_draw(all);
	return (0);
}

void	ft_free(t_all *all)
{
	if (all->img.ptr)
		mlx_destroy_image(all->info.mlx, all->img.ptr);
	if (all->sprite)
	{
		free(all->sprite);
		all->sprite = NULL;
	}
	exit(0);
}

int		main(int argc, char *argv[])
{
	t_all all;

	if (argc == 3 && ft_name_check(argv[1], ".cub")) // --save 부분 추가
	{//bmp 저장 하는 공간
		ft_init_cub3d(&all, argv[1]);
		all.img.ptr = mlx_new_image(all.info.mlx, all.info.win_x, all.info.win_y);//이미지 생성
		all.img.data = (int *)mlx_get_data_addr(all.img.ptr, &all.img.bpp, &all.img.size_l, &all.img.endian); //생성된 이미지에 대한 정보 설정
		ft_raycasting(&all);
		ft_sprite(&all);
		exit(0);
	}
	else if (argc == 2 && ft_name_check(argv[1], ".cub"))
	{
		ft_init_cub3d(&all, argv[1]);
		all.img.ptr = mlx_new_image(all.info.mlx, all.info.win_x, all.info.win_y);//이미지 생성
		all.img.data = (int *)mlx_get_data_addr(all.img.ptr, &all.img.bpp, &all.img.size_l, &all.img.endian); //생성된 이미지에 대한 정보 설정
		all.info.win = mlx_new_window(all.info.mlx, all.info.win_x, all.info.win_y, "Cub3d");
		mlx_hook(all.info.win, X_EVENT_KEY_PRESS, 1L<<0, &ft_key_press, &all);
		mlx_loop_hook(all.info.mlx, &ft_main_loop, &all);
		mlx_hook(all.info.win, X_EVENT_KEY_EXIT, 0, &ft_exit, &all);
		mlx_loop(all.info.mlx);
	}
	else
	{
		ft_error("[Error] Check argv and files");
	}
	return (0);
}
