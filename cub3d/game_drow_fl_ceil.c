/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drow_fl_ceil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:37:28 by pskip             #+#    #+#             */
/*   Updated: 2022/07/12 17:20:26 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drow_back(t_mlx_data *mlx_data, t_game_data *color)
{
	int		pixels_num;
	int		pixel;
	char	*dst;

	pixels_num = HEIGHT * WIDTH;
	pixel = 0;
	while (pixel < pixels_num / 2)
	{
		put_pixel(pixel, mlx_data, color->ceilling_color);
		pixel++;
	}
	while (pixel < pixels_num)
	{
		put_pixel(pixel, mlx_data, color->floor_color);
		pixel++;
	}
}
