/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:48:17 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/25 00:31:29 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_check_line(t_all *all, char *line)
{// 처음 글자에 따라 check 하는 곳
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'R')
		ft_resolution(all, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		ft_texture(all, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		ft_texture(all, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		ft_texture(all, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		ft_texture(all, line, &i);
	else if (line[i] == 'S')
		ft_texture(all, line, &i);
	// else if (line[i] == 'F')
	// 	ft_floor();
	// else if (line[i] == 'C')
	// 	ft_ceilling();
	// else if (line[i] == '1' || line[i] == '0')
	// 	ft_map();
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
		return (-1);//error
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

int		ft_parse(t_all *all, char *cub)
{
	int		ret;
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY); //cub는 파일 이름
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_check_line(all, line) == -1)
		{
			printf("Error");//error
			return (-1);
		}
		free(line);
	}
	close(fd);
	if (fd < 0)
	{
		print("Error");//error
		return (-1);
	}

}