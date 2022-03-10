/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:08 by pskip             #+#    #+#             */
/*   Updated: 2022/03/10 03:50:27 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaler(t_meta *data, int key)
{
	if (key == 69)
	{
		if (data->scale > 35 && data->scale < 150)
		{
			data->scale += (35 / data->scale);
		}
		else if (data->scale < 35)
			data->scale += 3;
	}
	if (key == 78)
	{
		if (data->scale > 3)
			data->scale -= 3;
		else
			data->scale = 1;
	}	
}

static void	rotator(int key, t_meta *data)
{
	if (key == 84)
		data->alfa += 0.05;
	if (key == 91)
		data->alfa -= 0.05;
	if (key == 86)
		data->beta += 0.05;
	if (key == 88)
		data->beta -= 0.05;
	if (key == 83)
		data->gamma += 0.05;
	if (key == 85)
		data->gamma -= 0.05;
}

int	key_hook(int key, t_meta *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 69 || key == 78)
		scaler(data, key);
	if (key == 81 && data->z_scale > -50)
		data->z_scale -= 1;
	if (key == 75 && data->z_scale < 50)
		data->z_scale += 1;
	if (key == 34)
		data->projection = 'i';
	if (key == 35)
		data->projection = 'p';
	if ((key >= 83 && key <= 92) && key != 90)
		rotator(key, data);
	if (key == 53)
		exit(0);
	drow_map(data);
	return (0);
}

int	event_hook(void)
{
	exit(0);
	return (0);
}
