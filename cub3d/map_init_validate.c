/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:40:51 by pskip             #+#    #+#             */
/*   Updated: 2022/07/06 16:46:18 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	is_start_correct(char elem, t_map *map, int pos)
{
	if (elem == 'N' || elem == 'S' || elem == 'E' || elem == 'W')
	{
		if (map->start != -1)
			error("more_then_one_start\n");
		map->start = pos;
		map->dir = elem;
	}
	else if (elem != '0' && elem != '1' && elem != ' ')
		error("unknown_litera_in_map\n");
}

void	ways_checker(int pos, t_map *map)
{
	if (pos < map->x_len || (pos % map->x_len == 0)
		|| (pos % map->x_len == map->x_len - 1)
		|| pos + map->x_len > map->x_len * map->y_len)
		error("not_closed_map");
	map->walid_visited[pos] = 1;
	if ((map->points[pos - map->x_len] == '0' || map->points[pos - map->x_len] == ' ')
		&& !map->walid_visited[pos - map->x_len])
		ways_checker(pos - map->x_len, map);
	if ((map->points[pos + map->x_len] == '0' || map->points[pos + map->x_len] == ' ')
		&& !map->walid_visited[pos + map->x_len])
		ways_checker(pos + map->x_len, map);
	if ((map->points[pos - 1] == '0' || map->points[pos - 1] == ' ')
		&& !map->walid_visited[pos - 1])
		ways_checker(pos - 1, map);
	if ((map->points[pos + 1] == '0' || map->points[pos + 1] == ' ')
		&& !map->walid_visited[pos + 1])
		ways_checker(pos + 1, map);
}

void	is_map_valid(t_map *map)
{
	int	pos;

	if (map->start == -1)
		error("start_not_founded\n");
	pos = map->start;
	ways_checker(pos, map);
}

int	add_line_to_array(t_map *map, char *line, int pos)
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

void	create_map(char *file_name, t_map *map, int map_first_line)
{
	int		fd;
	char 	*line;
	int		pos;

	fd = open(file_name, O_RDONLY);
	map->points = (char *) malloc(sizeof(char) * ((map->x_len * map->y_len)));
	map->walid_visited = (short *) malloc(sizeof(short) * ((map->x_len * map->y_len)));
	if (!map->points || !map->walid_visited)
		error("malloc cant init points\n");
	map->start = -1;
	line = get_next_line(fd);
	pos = 0;
	while(map_first_line > 0)
	{
		map_first_line--;
		free(line);
		line = get_next_line(fd);
	}
	while(line)
	{
		pos = add_line_to_array(map, line, pos);
		free(line);
		line = get_next_line(fd);
	}
	is_map_valid(map);
}