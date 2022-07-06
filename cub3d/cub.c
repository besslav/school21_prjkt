/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:06:22 by pskip             #+#    #+#             */
/*   Updated: 2022/07/06 21:24:11 by pskip            ###   ########.fr       */
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


int main(int ac, char **av)
{
	t_global	*global;
	//t_mlx_data		*data;

	if (ac != 2)
		error("bad argv\n");
	global = (t_global *) malloc(sizeof(t_global));
	if (!global)
		error("malloc_error\n");
	map_open(av[1], global);




	// data = (t_data *) malloc(sizeof(t_data));
	// if (!data)
	// 	error("malloc error\n");
	// data->mlx = mlx_init();
	// if (!data->mlx)
	// 	error("mlx_init_error\n");
	// data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "CUB");
	// data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	// if (!(data->mlx && data->img))
	// 	error("mlx_win_or_img_error\n");
	// data->addr = mlx_get_data_addr
	// 	(data->img, &data->bits_per_pixel,
	// 		&data->line_length, &data->endian);
	// if (!data->addr)
	// 	error("addr_err\n");

	
	//drow_image(data, global);


}