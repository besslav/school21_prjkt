/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:06:22 by pskip             #+#    #+#             */
/*   Updated: 2022/07/31 20:02:16 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (name[i - 1] != 'b' || name[i - 2] != 'u'
		|| name[i - 3] != 'c' || name[i - 4] != '.')
		error("bad_file_name\n");
}

static void	map_open(char *file_name, t_global	*global)
{
	int			fd;
	char		*line;

	check_name(file_name);
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

void	free_global(t_global *data)
{
	free(data->east);
	free(data->ceilling);
	free(data->floor);
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->map_data);
	free(data);
}

int	main(int ac, char **av)
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
	free_global(global);
	drow_image(all_data);
	mlx_loop_hook(all_data->mlx, lh_events, all_data);
	mlx_hook(all_data->win, 2, 0, key_hook, all_data);
	mlx_hook(all_data->win, 17, 0, event_hook, all_data);
	mlx_loop(all_data->mlx);
}
