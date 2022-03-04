/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:08 by pskip             #+#    #+#             */
/*   Updated: 2022/03/04 21:05:00 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	scaler(t_meta *data, int key)
{
	if (key == 69)
	{
		if (data->scale > 35)
		{
			data->scale += (35 / data->scale);
		}
		else
			data->scale += 3;
		data->z_scale = data->z_scale + data->scale / 5;
	}
	if (key == 78)
	{
		if (data->scale > 3)
			data->scale -= 3;
		else
			data->scale = 1;
		data->z_scale = data->z_scale - data->scale / 5;
	}	
}

int	deal_key(int key, t_meta *data)
{
	printf("%d\n", key);
	if (key == 126)
		data->shift_y -= 30;
	if (key == 125)
		data->shift_y += 30;
	if (key == 123)
		data->shift_x -= 30;
	if (key == 124)
		data->shift_x += 30;
	if (key == 69 || key == 78)
		scaler(data, key);
	if (key == 84)
		data->z_scale -= 3;
	if (key == 91)
		data->z_scale += 3;
	//if (key >= 83 && != 90 key <= 92)
	//	rotator(key, data); 
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
