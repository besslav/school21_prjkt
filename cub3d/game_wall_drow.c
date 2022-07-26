/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wall_drow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:51:18 by pskip             #+#    #+#             */
/*   Updated: 2022/07/26 18:15:36 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_pixel_color_from_img(t_img_data *textura, int x, int y)
{
	char	*pixel;

	pixel = textura->addr
		+ (y * textura->line_length + x * (textura->bits_per_pixel / 8));
	return (*(int *)pixel);
}

void	drow_line_of_wall(int h_wall, int screen_x, t_all_data *all_data)
{
	t_drow		drow;
	int			i;
	int			side;
	t_img_data	*wall;

	wall = all_data->textures->wall_textures;
	side = all_data->game_data->side;
	drow.x_in_img = wall[side].width
		* (all_data->game_data->x_img_pos);
	drow.step = (float)wall[side].height / (float)h_wall;
	drow.y_start = (HEIGHT - h_wall) / 2;
	i = -1;
	drow.y_in_img = 0;
	if (drow.y_start < 0)
	{
		i -= drow.y_start;
		drow.y_in_img += drow.step * (-drow.y_start);
		h_wall += drow.y_start;
	}
	while (++i < h_wall)
	{
		drow.color = get_pixel_color_from_img(&wall[side],
				drow.x_in_img, drow.y_in_img);
		put_pixel(screen_x, drow.y_start + i,
			all_data->screen_img_data, drow.color);
		drow.y_in_img += drow.step;
	}
}
