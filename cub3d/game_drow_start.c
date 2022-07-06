/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drow_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:27:52 by pskip             #+#    #+#             */
/*   Updated: 2022/07/06 22:32:24 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	wall_distance(void)
{
	
}



void    drow_image(t_global *game_data, t_mlx_data *mlx_data)
{
	float	alpa_player;
	float	x_player;
	float	y_player;

	if (game_data->map_data->dir = 'W')
		alpa_player = M_PI;
	else if (game_data->map_data->dir = 'E')
		alpa_player = 0;
	else if (game_data->map_data->dir = 'N')
		alpa_player = M_PI_2;
	else if (game_data->map_data->dir = 'S')
		alpa_player = 3 * M_PI_2;
	x_player = (float)(game_data->map_data->start % game_data->map_data->x_len) + 0.5;
	y_player = (float)(game_data->map_data->start / game_data->map_data->x_len) + 0.5;

}