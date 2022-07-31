/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:49:05 by pskip             #+#    #+#             */
/*   Updated: 2022/07/30 19:08:58 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	event_hook(void)
{
	exit(0);
	return (0);
}

void	count_new_player_pos(t_game_data *game, float dir)
{
	float	x_new;
	float	y_new;

	x_new = game->x_player + STEP * cos(game->alpha_player + dir);
	y_new = game->y_player - STEP * sin(game->alpha_player + dir);
	if (game->map[array_pos((int)x_new,
				(int)game->y_player, game->x_len)] != '1'
		&& game->map[array_pos((int)x_new,
				(int)game->y_player, game->x_len)] != '2')
		game->x_player = x_new;
	if (game->map[array_pos((int)game->x_player,
				(int)y_new, game->x_len)] != '1'
		&& game->map[array_pos((int)game->x_player,
				(int)y_new, game->x_len)] != '2')
		game->y_player = y_new;
}

int	key_hook(int key, t_all_data *all_data)
{
	if (key == 49)
		try_open_door(all_data->game_data);
	if (key == 53)
		exit(0);
	if (key == 13)
		count_new_player_pos(all_data->game_data, 0);
	if (key == 0)
		count_new_player_pos(all_data->game_data, M_PI_2);
	if (key == 1)
		count_new_player_pos(all_data->game_data, M_PI);
	if (key == 2)
		count_new_player_pos(all_data->game_data, -M_PI_2);
	if (key == 123)
		all_data->game_data->alpha_player += STEP_ALPHA;
	if (key == 124)
		all_data->game_data->alpha_player -= STEP_ALPHA;
	drow_image(all_data);
	return (0);
}

void	mouse_hook(t_all_data *all_data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(all_data->win, &x, &y);
	if (all_data->game_data->x_mouse > x)
	{
		all_data->game_data->alpha_player += 0.05;
		all_data->game_data->x_mouse = x;
		drow_image(all_data);
	}
	else if (all_data->game_data->x_mouse < x)
	{
		all_data->game_data->alpha_player -= 0.05;
		all_data->game_data->x_mouse = x;
		drow_image(all_data);
	}
}

int	lh_events(t_all_data *all_data)
{
	mouse_hook(all_data);
	if (doors_closer(all_data->game_data))
		drow_image(all_data);
	return (0);
}
