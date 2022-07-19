/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:06:22 by pskip             #+#    #+#             */
/*   Updated: 2022/07/19 20:39:08 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*map_open(char *file_name, t_global	*global)
{
	int			fd;
	char		*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error("the map cannot be opened\n");
	global->ceilling = NULL;
	global->east = NULL;
	global->floor = NULL;
	global->north = NULL;
	global->south = NULL;
	global->west = NULL;
	global->line_start = 0;
	line = add_info(fd, global);
	global->map_data = get_size(fd, line);
	close(fd);
	create_map(file_name, global->map_data, global->line_start);
	free(global->map_data->walid_visited);
}

int	event_hook(void)
{
	exit(0);
	return (0);
}

void	count_new_player_pos(t_game_data *game, float dir)
{
	float	x_new;
	float	y_new;

	x_new = game->x_player + STEP * cos(game->alpha_player + dir);
	y_new = game->y_player - STEP * sin(game->alpha_player + dir);

	if (game->map[array_pos((int)x_new, (int)y_new, game->x_len)] != '1')
	{
		game->x_player = x_new;
		game->y_player = y_new;
	}
}

int	key_hook(int key, t_all_data *all_data)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		count_new_player_pos(all_data->game_data, 0);
	if (key == 0)
		count_new_player_pos(all_data->game_data, M_PI_2);
	if (key == 1)
		count_new_player_pos(all_data->game_data, M_PI);
	if (key == 2)
		count_new_player_pos(all_data->game_data, -M_PI_2);
	if (key == 123)
		all_data->game_data->alpha_player += 0.08;
	if (key == 124)
		all_data->game_data->alpha_player -= 0.08;	
	drow_image(all_data);
	return (0);
}

int main(int ac, char **av)
{
	t_global	*global;
	t_all_data	*all_data;

	if (ac != 2)
		error("bad argv\n");
	global = (t_global *) malloc(sizeof(t_global));
	if (!global)
		error("malloc_error\n");
	map_open(av[1], global);
	all_data = (t_all_data *)malloc(sizeof(t_all_data));
	if (!all_data)
		error("all_data_malloc_error\n");	
	all_data_group(global, all_data);
	drow_image(all_data);
	mlx_hook(all_data->win, 2, 0, key_hook, all_data);
	mlx_hook(all_data->win, 17, 0, event_hook, all_data);
	mlx_loop(all_data->mlx);
}
