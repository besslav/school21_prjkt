/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_collector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:09:44 by pskip             #+#    #+#             */
/*   Updated: 2022/07/27 15:59:20 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

static void	check_after_empty_line(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		len = get_len(line);
		if (len > 0)
			error("empty_line\n");
		free(line);
		line = get_next_line(fd);
	}	
}

t_map	*get_size(int fd, char *line)
{
	int		row_len;
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		error("malloc_map_error\n");
	map->y_len = 0;
	map->x_len = 0;
	while (line)
	{
		row_len = get_len(line);
		if (row_len < 1)
			break ;
		map->y_len++;
		if (row_len > map->x_len)
			map->x_len = row_len;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		free(line);
		check_after_empty_line(fd);
	}
	return (map);
}
