/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_throw_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:52:49 by pskip             #+#    #+#             */
/*   Updated: 2022/07/24 21:11:46 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	two_rays(t_all_data *all_data, float step_alpha, int i)
{
	float	dist;
	float	wall_h;

	dist = ray_len(all_data->game_data, all_data->game_data->alpha_player
			+ ALPHA_DIF - step_alpha * i);
	if (dist > 0)
	{
		wall_h = HEIGHT / (dist * cos(ALPHA_DIF - step_alpha * i));
		drow_line_of_wall(wall_h, i, all_data);
	}
	dist = ray_len(all_data->game_data,
			all_data->game_data->alpha_player - step_alpha * i);
	if (dist > 0)
	{
		wall_h = HEIGHT / (dist * cos(step_alpha * i));
		drow_line_of_wall(wall_h, i + (WIDTH / 2) + (WIDTH % 2), all_data);
	}
}

void	throw_rays(t_all_data *all_data)
{
	float	step_alpha;
	int		i;
	float	y_step;
	float	alpha;

	i = 0;
	step_alpha = ALPHA_DIF / (WIDTH / 2);
	while (i < WIDTH / 2)
		two_rays(all_data, step_alpha, i++);
}
