/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drower.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:50:19 by pskip             #+#    #+#             */
/*   Updated: 2022/03/10 04:05:30 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_finder(float x, float y)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	if (x > y)
		return (x);
	return (y);
}

void	my_mlx_pixel_put(t_meta *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	choice_of_color(t_meta *data, float z, int col_max, int col_min)
{
	int	now;
	int	steps;

	if (!col_max)
		col_max = COL_MAX;
	if (!col_min)
		col_min = COL_MIN;
	steps = data->max - data->min;
	now = (int)z - data->min;
	if (steps != 0)
	{
		if (now == 0)
			data->color = get_a_color_gap(col_min, col_max, 0);
		else
			data->color = get_a_color_gap
				(col_min, col_max, (int)(now * 256 / steps - 1));
	}
	else
		data->color = 0xFF00;
}

void	drow_line(t_meta *data, t_element o1, t_element o2)
{
	float	step_x;
	float	step_y;
	float	step_z;
	float	pixel_data[3];
	int		max;

	step_x = o2.x - o1.x;
	step_y = o2.y - o1.y;
	step_z = o2.z - o1.z;
	max = max_finder(step_x, step_y);
	step_y /= max;
	step_x /= max;
	step_z /= max;
	pixel_data[0] = o1.x;
	pixel_data[1] = o1.y;
	pixel_data[2] = o1.z;
	while ((int)(pixel_data[0] - o2.x) || (int)(pixel_data[1] - o2.y))
	{
		choice_of_color(data, pixel_data[2], o1.color, o2.color);
		my_mlx_pixel_put(data, (int)pixel_data[0],
			(int)pixel_data[1], data->color);
		pixel_data[0] += step_x;
		pixel_data[1] += step_y;
		pixel_data[2] += step_z;
	}
}

void	drow_map(t_meta *data)
{
	int		x;
	int		y;

	ft_bzero(data->addr, HEIGHT * WIDTH * (data->bits_per_pixel / 8));
	rebuild_array(data);
	y = 0;
	while (y < data->row)
	{
		x = 0;
		while (x < data->col)
		{
			if (x < data->col - 1)
				drow_line(data, data->array[y][x], data->array[y][x + 1]);
			if (y < data->row - 1)
				drow_line(data, data->array[y][x], data->array[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
