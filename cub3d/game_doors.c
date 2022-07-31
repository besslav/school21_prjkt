/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:59:55 by pskip             #+#    #+#             */
/*   Updated: 2022/07/31 20:06:02 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	add_door_textur(
	t_img_data **wall_textures, void *mlx)
{
	char	*door;

	door = "./textures/door.xpm";
	(*wall_textures)[4].img = mlx_xpm_file_to_image(mlx, door,
			&(*wall_textures)[4].width, &(*wall_textures)[4].height);
	if (!(*wall_textures)[4].img)
		error("door_textur_error\n");
	(*wall_textures)[4].addr = mlx_get_data_addr
		((*wall_textures)[4].img, &(*wall_textures)[4].bits_per_pixel,
			&(*wall_textures)[4].line_length, &(*wall_textures)[4].endian);
	if (!(*wall_textures)[4].addr)
		error("door_texturs_init_addr_error\n");
}

t_doors	*door_init(int pos)
{
	t_doors	*door;

	door = (t_doors *) malloc(sizeof(t_doors));
	if (!door)
		error("door_malloc_error/n");
	door->door_pos = pos;
	door->time_open = 0;
	door->next_door = NULL;
	door->prev_door = NULL;
	return (door);
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
		new_door
			= door_init(array_pos((int)x_check, (int)y_check, game->x_len));
		if (!game->doors)
			game->doors = new_door;
		else
		{
			pos_for_new_door = game->doors;
			while (pos_for_new_door->next_door)
				pos_for_new_door = pos_for_new_door->next_door;
			pos_for_new_door->next_door = new_door;
			new_door->prev_door = pos_for_new_door;
		}
		game->map[new_door->door_pos] = '4';
	}
}

void	del_door(t_doors **door_too_del, t_game_data *game)
{
	if ((*door_too_del)->prev_door && (*door_too_del)->next_door)
	{
		(*door_too_del)->next_door->prev_door = (*door_too_del)->prev_door;
		(*door_too_del)->prev_door->next_door = (*door_too_del)->next_door;
	}
	else if ((*door_too_del)->next_door)
	{
		game->doors = (*door_too_del)->next_door;
		game->doors->prev_door = NULL;
	}
	else if ((*door_too_del)->prev_door)
	{
		(*door_too_del)->prev_door->next_door = NULL;
	}
	else
		game->doors = NULL;
	free(*door_too_del);
}

int	doors_closer(t_game_data *game)
{
	t_doors	*door_too_del;
	t_doors	*door;
	int		status;

	status = 0;
	if (game->doors)
	{
		door = game->doors;
		while (door)
		{
			door->time_open++;
			if (door->time_open > 25000 && (array_pos((int)game->x_player,
						(int)game->y_player, game->x_len) != door->door_pos))
			{
				game->map[door->door_pos] = '2';
				door_too_del = door;
				del_door(&door_too_del, game);
				door = door->next_door;
				status = 1;
			}
			else
				door = door->next_door;
		}
	}
	return (status);
}
