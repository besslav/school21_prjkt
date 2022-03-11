/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuilder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:59:31 by pskip             #+#    #+#             */
/*   Updated: 2022/03/11 03:50:58 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotater(t_meta *data, float *x, float *y, float *z)
{
	float	x_pre;
	float	y_pre;
	float	z_pre;

	x_pre = *x;
	y_pre = *y;
	z_pre = *z;
	*y = y_pre * cos(data->alfa) + *z * sin(data->alfa);
	*z = -y_pre * sin(data->alfa) + *z * cos(data->alfa);
	y_pre = *y;
	z_pre = *z;
	*x = x_pre * cos(data->beta) + *z * sin(data->beta);
	*z = -x_pre * sin(data->beta) + *z * cos(data->beta);
	x_pre = *x;
	z_pre = *z;
	*x = x_pre * cos(data->gamma) - y_pre * sin(data->gamma);
	*y = x_pre * sin(data->gamma) + y_pre * cos(data->gamma);
}

static void	new_point(t_meta *data, int x, int y, float *pre_data)
{
	if (data->projection == 'i')
	{
		data->array[y][x].x
			= (pre_data[0] - pre_data[1]) * cos(data->angle) + data->shift_x;
		data->array[y][x].y = (((pre_data[0] + pre_data[1]) * sin(data->angle))
				- (data->array[y][x].z * data->z_scale))
			+ data->shift_y;
	}
	else if (data->projection == 'p')
	{
		data->array[y][x].x = pre_data[0] + data->shift_x;
		data->array[y][x].y = pre_data[1] + data->shift_y;
	}
}

void	rebuild_array(t_meta *data)
{
	int		x;
	int		y;
	float	pre_data[3];

	y = 0;
	while (y < data->row)
	{
		x = 0;
		while (x < data->col)
		{
			pre_data[0] = (x * data->scale);
			pre_data[1] = (y * data->scale);
			pre_data[2] = data->array[y][x].z * data->scale / 10;
			rotater(data, &pre_data[0], &pre_data[1], &pre_data[2]);
			new_point(data, x, y, pre_data);
			x++;
		}
		y++;
	}
}
