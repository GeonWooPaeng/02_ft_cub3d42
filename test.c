/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:19:50 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/02 14:05:04 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_cub3d.h"

int main()
{
    t_all all;
    ft_parsing(&all, "./srcs/map.cub");
    printf("texture >> %s\n", all.tex.north_texture);
    printf("texture >> %s\n", all.tex.south_texture);
    printf("texture >> %s\n", all.tex.east_texture);
    printf("texture >> %s\n", all.tex.west_texture);
}