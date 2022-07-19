/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wall_drow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:51:18 by pskip             #+#    #+#             */
/*   Updated: 2022/07/19 15:57:06 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drow_line_of_wall(int h_wall, int x, t_all_data *all_data, int color)
{
	int	i;
	int	y_start;
	
	i = 0;
	y_start = (HEIGHT - h_wall) / 2;
	while (i < h_wall)
	{
		put_pixel(x, y_start + i, all_data->screen_img_data, color);
		i++;
	}
}
