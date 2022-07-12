/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:06:22 by pskip             #+#    #+#             */
/*   Updated: 2022/07/12 21:08:15 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void map_open(char *file_name, t_global *global)
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

void	game_data_collect(t_game_data *game, t_global *info)
{
	if (info->map_data->dir == 'W')
		game->alpha_player = M_PI;
	else if (info->map_data->dir == 'E')
		game->alpha_player = 0;
	else if (info->map_data->dir == 'N')
		game->alpha_player = M_PI_2;
	else if (info->map_data->dir == 'S')
		game->alpha_player = 3 * M_PI_2;
	game->x_player = (float)(info->map_data->start % info->map_data->x_len) + 0.5;
	game->y_player = (float)(info->map_data->start / info->map_data->x_len) + 0.5;
	game->map = info->map_data->points;
	game->x_len = info->map_data->x_len;
	game->y_len = info->map_data->y_len;
	pars_colors_line(info, game);
}

void	mlx_data_collect(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		error("mlx_init_error\n");
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "CUB");
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	if (!(mlx_data->mlx && mlx_data->img))
		error("mlx_win_or_img_error\n");
	mlx_data->addr = mlx_get_data_addr
		(mlx_data->img, &mlx_data->bits_per_pixel,
			&mlx_data->line_length, &mlx_data->endian);
	if (!mlx_data->addr)
		error("addr_err\n");
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
		all_data->game_data->alpha_player += 0.03;
	if (key == 124)
		all_data->game_data->alpha_player -= 0.03;	
	drow_image(all_data);
	return (0);
}

t_all_data	*all_data_group(t_game_data *game_data, t_mlx_data *mlx_data)
{
	t_all_data	*all_data;

	all_data = (t_all_data *)malloc(sizeof(all_data));
	if (!all_data)
		error("all_data_malloc_error\n");
	all_data->game_data = game_data;
	all_data->mlx_data = mlx_data;
	return (all_data);
}

int main(int ac, char **av)
{
	t_global	*global;
	t_mlx_data	*mlx_data;
	t_game_data	*game_data;
	t_all_data	*all_data;

	if (ac != 2)
		error("bad argv\n");
	global = (t_global *) malloc(sizeof(t_global));
	if (!global)
		error("malloc_error\n");
	map_open(av[1], global);

	game_data = (t_game_data *) malloc(sizeof(t_game_data));
	if (!game_data)
		error("game_malloc error\n");	
	mlx_data = (t_mlx_data *) malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		error("plx_malloc error\n");

	game_data_collect(game_data, global);
	mlx_data_collect(mlx_data);
	all_data = all_data_group(game_data, mlx_data);

	
	drow_image(all_data);
	mlx_hook(mlx_data->win, 2, 0, key_hook, all_data);
	mlx_hook(mlx_data->win, 17, 0, event_hook, all_data);
	mlx_loop(mlx_data->mlx);
}