/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:43:52 by pskip             #+#    #+#             */
/*   Updated: 2022/03/11 03:53:04 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	new_line_creator(char **pre_mass, t_element *step_mass,
							int line, t_meta *data)
{
	int	j;

	j = -1;
	while (pre_mass[++j])
	{
		step_mass[j].z = ft_atoi(pre_mass[j]);
		step_mass[j].color = get_color(pre_mass[j]);
		if (line == 0 && j == 0)
		{
			data->max = step_mass[j].z;
			data->min = step_mass[j].z;
		}
		if (data->max < step_mass[j].z)
			data->max = step_mass[j].z;
		if (data->min > step_mass[j].z)
			data->min = step_mass[j].z;
	}
}

static void	map_creator(int fd, t_meta *data)
{
	int		line;
	char	*str;
	char	**pre_mass;
	int		len;

	line = -1;
	str = gnl(fd);
	while (str)
	{
		pre_mass = ft_split(str, ' ');
		if (!pre_mass)
			errors("split error\n", 12);
		len = ft_numslen(pre_mass);
		if (data->col && data->col != len)
			errors("incorrect map\n", 14);
		data->col = len;
		data->array[++line] = (t_element *)malloc(len * sizeof(t_element));
		if (!data->array[line])
			errors("malloc error\n", 13);
		new_line_creator(pre_mass, data->array[line], line, data);
		cleaner(pre_mass, len);
		free(str);
		str = gnl(fd);
	}
	close(fd);
}

static void	count_rows(char *map_name, t_meta *data)
{
	char	*str;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		errors("cant open\n", 10);
	str = gnl(fd);
	if (!str)
		errors("empty file\n", 11);
	while (str)
	{
		data->row++;
		free(str);
		str = gnl(fd);
	}
	close(fd);
}

static void	set_basic_value(t_meta *data)
{
	data->col = 0;
	data->row = 0;
	data->scale = 20;
	data->shift_x = 450;
	data->shift_y = 200;
	data->z_scale = 1;
	data->angle = 0.523599;
	data->alfa = 0;
	data->beta = 0;
	data->gamma = 0;
	data->projection = 'i';
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		errors("mlx_init_error\n", 15);
	data->win_ptr = mlx_new_window(data->mlx_ptr, HEIGHT, WIDTH, "FDF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	if (!(data->mlx_ptr && data->img_ptr))
		errors("mlx_win_or_img_error\n", 21);
	data->addr = mlx_get_data_addr
		(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		errors("addr_err\n", 9);
}

int	main(int ac, char **av)
{
	t_meta	*data;
	int		fd;

	if (ac != 2)
		errors("incorrect number of arguments\n", 30);
	data = (t_meta *) malloc(sizeof(t_meta));
	if (!data)
		errors("malloc error\n", 13);
	set_basic_value(data);
	count_rows(av[1], data);
	data->array = (t_element **)malloc(data->row * sizeof(t_element *));
	if (!data->array)
		errors("malloc error\n", 13);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		errors("cant open\n", 10);
	map_creator(fd, data);
	if (data->row * data->col > 1000)
		data->scale = 5;
	if (data->row * data->col > 10000)
		data->scale = 1;
	drow_map(data);
	mlx_hook(data->win_ptr, 2, 0, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, event_hook, data);
	mlx_loop(data->mlx_ptr);
}
