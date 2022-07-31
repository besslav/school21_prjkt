/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:33:56 by pskip             #+#    #+#             */
/*   Updated: 2022/07/31 20:03:43 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	array_pos(int x, int y, int x_len)
{
	return (y * x_len + x);
}

int	newcolor(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error("bad_color_line\n");
	return (((0xFF & (r)) << 16) | ((0xFF & (g)) << 8) | (0xFF & (b)));
}

void	put_pixel(int x, int y, t_img_data *img_data, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img_data->addr + (y * img_data->line_length
				+ x * (img_data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

int	find_door(t_game_data *game)
{
	game->side = 4;
	return (1);
}

float	get_len_of_ray(char x_y, t_ray *ray)
{
	if (x_y == 'x')
		return (ray->x_ray_len);
	return (ray->y_ray_len);
}
