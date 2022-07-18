/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_throw_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:52:49 by pskip             #+#    #+#             */
/*   Updated: 2022/07/18 20:47:39 by pskip            ###   ########.fr       */
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

int is_wall(t_ray *ray, float alpha, t_game_data *game_data, char x_y)
{
	float		x;
	float		y;
	float		len;

	if (x_y == 'x')
		len = ray->x_ray_len;
	else if (x_y == 'y')
		len = ray->y_ray_len;
	x = (game_data->x_player + cos(alpha) * len);
	y = (game_data->y_player - sin(alpha) * len);
	if (x_y == 'y' && ray->y_dir == -1)
		y -= 1;
	if (x_y == 'x' && ray->x_dir == -1)
		x -= 1;
	if (game_data->map[array_pos((int)x, (int)y, game_data->x_len)] == '1')
		return (1);
	return (0);	
}

float	ray_cycle(t_ray *ray_info, t_game_data *game_data, float alpha)
{
	while (ray_info->x_ray_len < 15 || ray_info->y_ray_len < 15)
	{
		if (ray_info->y_ray_len < ray_info->x_ray_len)
		{
			if (!is_wall(ray_info, alpha, game_data, 'y'))
			{
				ray_info->y_pos += ray_info->y_dir;
				ray_info->y_ray_len = (game_data->y_player - ray_info->y_pos) / sin(alpha);
			}
			else
				return (ray_info->y_ray_len);
		}
		else
		{
			if (!is_wall(ray_info, alpha, game_data, 'x'))
			{
				ray_info->x_pos += ray_info->x_dir;
				ray_info->x_ray_len = (ray_info->x_pos - game_data->x_player) / cos(alpha);
			}
			else
				return (ray_info->x_ray_len);
		}
	}
	return (-1);
}

void	setap(t_ray *ray_info, t_game_data *game, float alpha)
{
	ray_info->x_dir = 1;
	ray_info->y_dir = 1;
	ray_info->x_pos = (int)game->x_player;
	ray_info->y_pos = (int)game->y_player;
	if (sin(alpha) > 0)
		ray_info->y_dir = -1;
	if (cos(alpha) < 0)
		ray_info->x_dir = -1;
	if (ray_info->x_dir == 1)
		ray_info->x_pos += 1;
	if (ray_info->y_dir == 1)
		ray_info->y_pos += 1;
}

float	x_only(t_ray *ray_info, float alpha, t_game_data *game)
{
	ray_info->x_dir = 1;
	if (cos(alpha) < 0)
		ray_info->x_dir = -1;
	ray_info->x_pos = (int)game->x_player;
	if (ray_info->x_dir == 1)
		ray_info->x_pos += 1;
	ray_info->x_ray_len = (ray_info->x_pos - game->x_player) / cos(alpha);
	while (ray_info->x_ray_len < 15)
	{
		if (!is_wall(ray_info, alpha, game, 'x'))
		{
			ray_info->x_pos += ray_info->x_dir;
			ray_info->x_ray_len = (ray_info->x_pos - game->x_player) / cos(alpha);
		}
		else
			return (ray_info->x_ray_len);		
	}
	return (-1);
}

float	y_only(t_ray *ray_info, float alpha, t_game_data *game)
{
	ray_info->y_dir = 1;
	if (sin(alpha) > 0)
		ray_info->y_dir = -1;
	ray_info->y_pos = (int)game->y_player;
	if (ray_info->y_dir == 1)
		ray_info->y_pos += 1;
	ray_info->y_ray_len = (game->y_player - ray_info->y_pos) / sin(alpha);
	while (ray_info->y_ray_len < 15)
	{
		if (!is_wall(ray_info, alpha, game, 'y'))
		{
			ray_info->y_pos += ray_info->y_dir;
			ray_info->y_ray_len = (game->y_player - ray_info->y_pos) / sin(alpha);
		}
		else
			return (ray_info->y_ray_len);
	}
	return (-1);
}

float	ray_len(t_game_data *game, float alpha)
{
	t_ray   *ray_info;
	float	len;

	ray_info = (t_ray *)malloc(sizeof(t_ray));
	if (!ray_info)
		error("rey_malloc_error\n");
	if (cos(alpha) < 0.001 && cos(alpha) > -0.001)
		len = (y_only(ray_info, alpha, game));
	else if (sin(alpha) < 0.001 && sin(alpha) > 0.001)
		len = (x_only(ray_info, alpha, game));
	else
	{
		setap(ray_info, game, alpha);
		ray_info->x_ray_len = (ray_info->x_pos - game->x_player) / cos(alpha);
		ray_info->y_ray_len = (game->y_player - ray_info->y_pos) / sin(alpha);
		len = ray_cycle(ray_info, game, alpha);
	}
	free(ray_info);
	return (len);
}



void	two_ray(t_all_data *all_data, float step_alpha, int i)
{
	float	dist;
	float	wall_h;
	int		wall_side;

	// dist = wall_distance(all_data->game_data,
	// 					all_data->game_data->alpha_player + ALPHA_DIF - step_alpha * i);
	dist = ray_len(all_data->game_data, all_data->game_data->alpha_player + ALPHA_DIF - step_alpha * i);
	if (dist > 0)
	{
		wall_h = HEIGHT / (dist * cos(ALPHA_DIF - step_alpha * i));
		// wall_side = choice_size_of_wall(all_data->game_data, dist,
		// 								all_data->game_data->alpha_player + ALPHA_DIF - step_alpha * i);
		drow_line_of_wall(wall_h, i, all_data->screen_img_data, all_data->textures->walls[0]);	
	}
	// dist = wall_distance(all_data->game_data,
	// 					all_data->game_data->alpha_player - step_alpha * i);
	dist = ray_len(all_data->game_data, all_data->game_data->alpha_player - step_alpha * i);
	if (dist > 0)
	{
		wall_h = HEIGHT / (dist * cos(step_alpha * i));
		// wall_side = choice_size_of_wall(all_data->game_data, dist,
		// 								all_data->game_data->alpha_player + ALPHA_DIF - step_alpha * i);
		drow_line_of_wall(wall_h, i + 400, all_data->screen_img_data, all_data->textures->walls[0]);
	}
}

void	throw_rays(t_all_data *all_data)
{
	float	step_alpha;
	int		i;

	i = 0;
	step_alpha = ALPHA_DIF / (WIDTH / 2);
	while (i < WIDTH / 2)
	//while (i < 20)
		two_ray(all_data, step_alpha, i++);

}