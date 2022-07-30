/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:07:45 by pskip             #+#    #+#             */
/*   Updated: 2022/07/30 19:02:49 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ways_checker(int pos, t_map *map)
{
	if (pos < map->x_len || (pos % map->x_len == 0)
		|| (pos % map->x_len == map->x_len - 1)
		|| pos + map->x_len > map->x_len * map->y_len
		|| map->points[pos] == ' ')
		error("bad_map\n");
	map->walid_visited[pos] = 1;
	if (map->points[pos - map->x_len] != '1'
		&& !map->walid_visited[pos - map->x_len])
		ways_checker(pos - map->x_len, map);
	if (map->points[pos + map->x_len] != '1'
		&& !map->walid_visited[pos + map->x_len])
		ways_checker(pos + map->x_len, map);
	if (map->points[pos - 1] != '1'
		&& !map->walid_visited[pos - 1])
		ways_checker(pos - 1, map);
	if (map->points[pos + 1] != '1'
		&& !map->walid_visited[pos + 1])
		ways_checker(pos + 1, map);
}

void	is_map_close(t_map *map)
{
	int	pos;

	if (map->start == -1)
		error("start_not_founded\n");
	pos = map->start;
	ways_checker(pos, map);
}
