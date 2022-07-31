/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_throw_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:52:49 by pskip             #+#    #+#             */
/*   Updated: 2022/07/31 20:04:14 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static float	ray_len(t_game_data *game, float alpha)
{
	t_ray	ray_info;

	ray_info.x_dir = 1;
	ray_info.y_dir = 1;
	ray_info.x_pos = floor(game->x_player);
	ray_info.y_pos = floor(game->y_player);
	if (sin(alpha) > 0)
		ray_info.y_dir = -1;
	if (cos(alpha) < 0)
		ray_info.x_dir = -1;
	if (ray_info.x_dir == 1)
		ray_info.x_pos += 1;
	if (ray_info.y_dir == 1)
		ray_info.y_pos += 1;
	ray_info.x_ray_len = (ray_info.x_pos - game->x_player) / cosf(alpha);
	ray_info.y_ray_len = (game->y_player - ray_info.y_pos) / sinf(alpha);
	return (ray_cycle(&ray_info, game, alpha));
}

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

	i = 0;
	step_alpha = ALPHA_DIF / (WIDTH / 2);
	while (i < WIDTH / 2)
		two_rays(all_data, step_alpha, i++);
}
