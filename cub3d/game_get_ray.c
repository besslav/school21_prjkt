/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_get_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:04:21 by pskip             #+#    #+#             */
/*   Updated: 2022/07/25 21:14:20 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_side(t_ray *ray, char x_y)
{
	if (ray->x_dir == 1)
	{
		if (x_y == 'x')
			return (WEST);
		if (ray->y_dir == 1)
			return (NORTH);
		return (SOUTH);
	}
	if (x_y == 'x')
		return (EAST);
	if (ray->y_dir == 1)
		return (NORTH);
	return (SOUTH);
}

static int	is_wall(t_ray *ray, float alpha, t_game_data *game_data, char x_y)
{
	float		x;
	float		y;
	float		len;

	if (x_y == 'x')
		len = ray->x_ray_len;
	else if (x_y == 'y')
		len = ray->y_ray_len;
	x = (game_data->x_player + cosf(alpha) * len);
	y = (game_data->y_player - sinf(alpha) * len);
	if (x_y == 'x')
		game_data->x_img_pos = y - floor(y);
	else
		game_data->x_img_pos = x - floor(x);
	game_data->side = get_side(ray, x_y);
	if (x_y == 'y' && ray->y_dir == -1)
		y -= 1;
	if (x_y == 'x' && ray->x_dir == -1)
		x -= 1;
	y += 0.000001;
	if (game_data->map[array_pos((int)x, (int)y, game_data->x_len)] == '1'
		|| game_data->map[array_pos((int)x, (int)y, game_data->x_len)] == '2')
		return (1);
	return (0);
}

static void	ray_info_val_upd(t_ray *ray_info,
	t_game_data *game_data, float alpha, char x_y)
{
	if (x_y == 'y')
	{
		ray_info->y_pos += (float)ray_info->y_dir;
		ray_info->y_ray_len
			= (game_data->y_player - ray_info->y_pos) / sinf(alpha);
	}
	else
	{
		ray_info->x_pos += (float)ray_info->x_dir;
		ray_info->x_ray_len
			= (ray_info->x_pos - game_data->x_player) / cosf(alpha);
	}
}

static float	ray_cycle(t_ray *ray_info, t_game_data *game_data, float alpha)
{
	while (ray_info->x_ray_len < 20 || ray_info->y_ray_len < 20)
	{
		if (ray_info->y_ray_len < ray_info->x_ray_len)
		{
			if (!is_wall(ray_info, alpha, game_data, 'y'))
				ray_info_val_upd(ray_info, game_data, alpha, 'y');
			else
				return (ray_info->y_ray_len);
		}
		else
		{
			if (!is_wall(ray_info, alpha, game_data, 'x'))
				ray_info_val_upd(ray_info, game_data, alpha, 'x');
			else
				return (ray_info->x_ray_len);
		}
	}
	return (-1);
}

float	ray_len(t_game_data *game, float alpha)
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
