/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:40:51 by pskip             #+#    #+#             */
/*   Updated: 2022/07/25 21:48:09 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	is_start_correct(char elem, t_map *map, int pos)
{
	if (elem == 'N' || elem == 'S' || elem == 'E' || elem == 'W')
	{
		if (map->start != -1)
			error("more_then_one_start\n");
		map->start = pos;
		map->dir = elem;
	}
	else if (elem != '0' && elem != '1' && elem != ' ' && elem != '2')
		error("unknown_litera_in_map\n");
}

static int	add_line_to_array(t_map *map, char *line, int pos)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		is_start_correct(line[i], map, pos);
		map->walid_visited[pos] = 0;
		map->points[pos++] = line[i];
		i++;
	}
	while (i++ < map->x_len)
		map->points[pos++] = ' ';
	return (pos);
}

static void	map_malloc(t_map *map)
{
	map->points = (char *) malloc
		(sizeof(char) * ((map->x_len * map->y_len + 1)));
	map->walid_visited = (short *) malloc
		(sizeof(short) * ((map->x_len * map->y_len)));
	if (!map->points || !map->walid_visited)
		error("malloc cant init points\n");
}

void	create_map(char *file_name, t_map *map, int map_first_line)
{
	int		fd;
	char	*line;
	int		pos;

	fd = open(file_name, O_RDONLY);
	map_malloc(map);
	map->start = -1;
	line = get_next_line(fd);
	pos = 0;
	while (map_first_line-- > 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		pos = add_line_to_array(map, line, pos);
		free(line);
		line = get_next_line(fd);
	}
	map->points[pos] = '\0';
	is_map_close(map);
}
