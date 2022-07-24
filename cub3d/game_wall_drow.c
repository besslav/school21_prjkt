/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wall_drow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:51:18 by pskip             #+#    #+#             */
/*   Updated: 2022/07/24 14:59:46 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_pixel_color_from_img(t_img_data *textura, int x, int y)
{
	char	*pixel;
	pixel = textura->addr + (y * textura->line_length + x * (textura->bits_per_pixel / 8));
	return (*(int*)pixel);
}


void	drow_line_of_wall(int h_wall, int x, t_all_data *all_data)
{
	float	y_pos;
	int		y_start;
	int		color;
	float	step;
	int		i;
	int		x_in_img;
	float		y_in_img;

	x_in_img = all_data->textures->wall_textures[all_data->game_data->side].width
		* (all_data->game_data->x_img_pos);
	step = (float)all_data->textures->wall_textures[all_data->game_data->side].height / (float)h_wall;
	y_start = (HEIGHT - h_wall) / 2;
	i = -1;
	y_in_img = 0;
	while (++i < h_wall)
	{
		color = get_pixel_color_from_img(&all_data->textures->wall_textures[all_data->game_data->side], x_in_img, (int)y_in_img);
		put_pixel(x, y_start + i, all_data->screen_img_data, color);
		y_in_img += step;
	}
}
