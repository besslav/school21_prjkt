/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_throw_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:52:49 by pskip             #+#    #+#             */
/*   Updated: 2022/07/13 20:06:15 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	wall_distance(t_game_data *game, float angle)
{
	float	dist;
	float	x_new;
	float	y_new;

	dist = 0;
	while(dist < 20)
	{
		x_new = game->x_player + dist * cos(angle);
		y_new = game->y_player - dist * sin(angle);
		if (game->map[array_pos((int)x_new, (int)y_new, game->x_len)] == '1')
			return (dist);
		else
			dist += 0.05; 
	}
	return (-1);
}

int	choice_size_of_wall(t_game_data *game_data, float dist, float angle)
{
	float	x_wall;
	float	y_wall;
	float	min_diff;
	int		side;

	x_wall = game_data->x_player + dist * cos(angle);
	y_wall = game_data->y_player - dist * sin(angle);
	min_diff = x_wall - (int) x_wall;
	if (y_wall - (int) y_wall < min_diff)
	{
		min_diff = y_wall - (int) y_wall;
		if (min_diff < 0.03)
			side = NORTH;
		else
			side = SOUTH;
	}
	else
	{
		if (min_diff < 0.03)
			side = WEST;
		else
			side = EAST;
	}
	return (side);
}

void	two_ray(t_all_data *all_data, float step_alpha, int i)
{
	float	dist;
	float	wall_h;
	int		wall_side;

	dist = wall_distance(all_data->game_data,
						all_data->game_data->alpha_player + ALPHA_DIF - step_alpha * i);
	if (dist > 0)
	{
		wall_h = HEIGHT / (dist * cos(ALPHA_DIF - step_alpha * i));
		wall_side = choice_size_of_wall(all_data->game_data, dist,
										all_data->game_data->alpha_player + ALPHA_DIF - step_alpha * i);
		drow_line_of_wall(wall_h, i, all_data->screen_img_data, all_data->textures->walls[0]);	
	}
	dist = wall_distance(all_data->game_data,
						all_data->game_data->alpha_player - step_alpha * i);
	if (dist > 0)
	{
		wall_h = HEIGHT / (dist * cos(step_alpha * i));
		wall_side = choice_size_of_wall(all_data->game_data, dist,
										all_data->game_data->alpha_player + ALPHA_DIF - step_alpha * i);
		drow_line_of_wall(wall_h, i + 400, all_data->screen_img_data, all_data->textures->walls[0]);
	}
}

void	throw_rays(t_all_data *all_data)
{
	float	step_alpha;
	int		i;

	i = 0;
	step_alpha = ALPHA_DIF / (WIDTH / 2);
	while (i < (WIDTH / 2))
		two_ray(all_data, step_alpha, i++);

}