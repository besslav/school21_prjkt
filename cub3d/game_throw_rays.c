/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_throw_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:52:49 by pskip             #+#    #+#             */
/*   Updated: 2022/07/23 15:33:54 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_side(t_ray *ray, char x_y)
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

int is_wall(t_ray *ray, float alpha, t_game_data *game_data, char x_y)
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
		game_data->x_img_global_pos = y;
	else
		game_data->x_img_global_pos = x;
	game_data->side = get_side(ray, x_y);
	if (x_y == 'y' && ray->y_dir == -1)
		y -= 1;
	if (x_y == 'x' && ray->x_dir == -1)
		x -= 1;
	y += 0.000001;
	if (game_data->map[array_pos((int)x, (int)y, game_data->x_len)] == '1')
		return (1);
	return (0);	
}

float	ray_cycle(t_ray *ray_info, t_game_data *game_data, float alpha)
{
	while (ray_info->x_ray_len < 20 || ray_info->y_ray_len < 20)
	{
		if (ray_info->y_ray_len < ray_info->x_ray_len)
		{
			if (!is_wall(ray_info, alpha, game_data, 'y'))
			{
				ray_info->y_pos += (float)ray_info->y_dir;
				ray_info->y_ray_len = (game_data->y_player - ray_info->y_pos) / sinf(alpha);
			}
			else
				return (ray_info->y_ray_len);
		}
		else
		{
			if (!is_wall(ray_info, alpha, game_data, 'x'))
			{
				ray_info->x_pos += (float)ray_info->x_dir;
				ray_info->x_ray_len = (ray_info->x_pos - game_data->x_player) / cosf(alpha);
			}
			else
				return (ray_info->x_ray_len);
		}
	}
	return (-1);
}

float	ray_len(t_game_data *game, float alpha)
{
	t_ray   ray_info;

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

void	two_ray(t_all_data *all_data, float step_alpha, int i)
{
	float	dist;
	float	wall_h;

	dist = ray_len(all_data->game_data, all_data->game_data->alpha_player + ALPHA_DIF - step_alpha * i);
	if (dist > 0)
	{
		wall_h = HEIGHT / (dist * cos(ALPHA_DIF - step_alpha * i));
		drow_line_of_wall(wall_h, i, all_data);	
	}
	dist = ray_len(all_data->game_data, all_data->game_data->alpha_player - step_alpha * i);
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
		two_ray(all_data, step_alpha, i++);

}

// void	throw_rays(t_all_data *all_data)
// {
// 	float	y_step;
// 	float	y_start;
// 	float	alpha;
// 	//float	alpha_dif;
// 	int		i;
// 	float	dist;
// 	float	wall_h;

// 	y_start = 10 / tan(ALPHA_DIF);
// 	y_step = (y_start * 2) / WIDTH;
// 	i = -1;
// 	while (++i < WIDTH)
// 	{
// 		alpha = all_data->game_data->alpha_player + atan(10 / (y_start - y_step * i));
// 		printf("%f--%d\n", alpha, i);
// 		dist = ray_len(all_data->game_data, alpha);
// 		if (dist > 0)
// 		{
// 			wall_h = HEIGHT / (dist);
// 			drow_line_of_wall(wall_h, i, all_data);	
// 		}
// 	}



// }