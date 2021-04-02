/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:48:17 by gpaeng            #+#    #+#             */
/*   Updated: 2021/04/02 14:09:47 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_cub3d.h"
#include "../../includes/ft_cub3d.h"

int		ft_check_line(t_all *all, char *line)
{// 처음 글자에 따라 check 하는 곳
	int	i;

	i = 0;
	ft_isspace(line, &i);
	if (line[i] == 'R')
		ft_resolution(all, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		all->info.error_n = ft_texture(all, line, &i, NORTH);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		all->info.error_n = ft_texture(all, line, &i, SOUTH);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		all->info.error_n = ft_texture(all, line, &i, WEST);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		all->info.error_n = ft_texture(all, line, &i,EAST);
	else if (line[i] == 'S')
		all->info.error_n = ft_texture(all, line, &i, SPRITE);
	else if (line[i] == 'F')
		all->info.error_n = ft_color(all, line, &i, FLOOR);
	else if (line[i] == 'C')
		all->info.error_n = ft_color(all, line, &i, CEILING);
	else if (line[i] != '\0')
		all->info.error_n = ft_map(all, line, &i);
	return (1);
}

char	*ft_make_line(char **arr, int *check)
{
	char *new_lineptr;
	char *backup;
	char *tmp;

	new_lineptr = ft_strchr(*arr, '\n');
	if (new_lineptr)
	{
		*check = 1;
		backup = ft_strndup(*arr, new_lineptr - *arr);
		tmp = ft_strndup(new_lineptr + 1, ft_strlen(new_lineptr + 1));
		free(*arr);
		*arr = tmp;
		return (backup);
	}
	else
	{
		*check = 0;
		return (*arr);
	}
}

int		ft_make_arr(char **arr, char *buf, ssize_t nr)
{
	char *backup;
	
	if (*arr == NULL)
	{
		backup = ft_strndup(buf, nr);
	}
	else
	{
		backup = ft_strjoin(*arr, buf);
		free(*arr);
	}
	*arr = backup;
	if (ft_strchr(*arr, '\n'))
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*arr[256];
	char		buf[4096];
	ssize_t		nr;
	int			check;

	if (!line || fd < 0 || fd >= 256)
		return (-1); //error
	while ((nr = read(fd, buf, 4096)) >= 0)
	{
		buf[nr] = '\0';
		if (ft_make_arr(&arr[fd], buf, nr) || nr == 0)
			break ;
	}
	if (nr < 0)
		return (-1); //error
	*line = ft_make_line(&arr[fd], &check);
	if (!check)
	{
		arr[fd] = 0;
		return (0);
	}
	return (1);
}

int		ft_parsing(t_all *all, char *cub)
{
	int		ret;
	int		fd;
	char	*line;

	ret = 1;
	fd = open(cub, O_RDONLY); //cub는 파일 이름
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_check_line(all, line) == 0)
			ret = -1;
		free(line);
	}
	close(fd);
	if (ret < 0)
	{
		printf("Error"); //error
		return (-1);
	}
	for (int i = 0; i < all->map.height; i++)
	{
		for (int j = 0; j < all->map.width; j++)
		{
			printf("%c",all->map.tab[i][j]);
		}
		printf("\n");
	}
	ft_position(all);
	return (1);
}