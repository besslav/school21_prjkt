/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:49:05 by pskip             #+#    #+#             */
/*   Updated: 2022/07/26 20:40:15 by pskip            ###   ########.fr       */
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
				(int)game->y_player, game->x_len)] != '1')
		game->x_player = x_new;
	if (game->map[array_pos((int)game->x_player,
				(int)y_new, game->x_len)] != '1')
		game->y_player = y_new;

}

void	try_open_door(t_game_data *game)
{
	float	x_check;
	float	y_check;
	t_doors	*new_door;
	t_doors	*pos_for_new_door;

	x_check = game->x_player + cos(game->alpha_player);
	y_check = game->y_player - sin(game->alpha_player);
	if (game->map[array_pos((int)x_check, (int)y_check, game->x_len)] == '2')
	{
		new_door = (t_doors *) malloc(sizeof(t_doors));
		if (!new_door)
			error("door_malloc_error/n");
		new_door->door_pos = array_pos((int)x_check, (int)y_check, game->x_len);
		new_door->time_open = 0;
		new_door->next_door = NULL;
		if (!game->doors)
			game->doors = new_door;
		else
		{
			pos_for_new_door = game->doors;
			while (pos_for_new_door->next_door)
				pos_for_new_door = pos_for_new_door->next_door;
			pos_for_new_door->next_door = new_door;
		}
		game->map[array_pos(x_check, y_check, game->x_len)] = '4';
	}
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
		all_data->game_data->alpha_player += 0.05;
	if (key == 124)
		all_data->game_data->alpha_player -= 0.05;
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

int	doors_closer(t_game_data *game)
{
	t_doors *door_too_del;
	t_doors *door;
	int		status;

	status = 0;
	if (game->doors)
	{
		door = game->doors;
		while(door)
		{
			door->time_open++;
			if (door->time_open > 40000 && (array_pos((int)game->x_player,
				(int)game->y_player, game->x_len) != door->door_pos))
			{
				game->map[door->door_pos] = '2';
				door_too_del = door;
				door = door->next_door;
				game->doors = door;
				status = 1;
				free(door_too_del);
			}
			else
				door = door->next_door;
		}
	}
	return (status);
}

int	lh_events(t_all_data *all_data)
{
	mouse_hook(all_data);
	if (doors_closer(all_data->game_data))
		drow_image(all_data);
	return (0);
}