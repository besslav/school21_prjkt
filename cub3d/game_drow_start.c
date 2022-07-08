/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drow_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:27:52 by pskip             #+#    #+#             */
/*   Updated: 2022/07/08 21:03:09 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drow_back(t_mlx_data *mlx_data, t_game_data *color)
{
	int		pixels_num;
	int		pixel;
	char	*dst;

	pixels_num = HEIGHT * WIDTH;
	pixel = 0;
	while (pixel < pixels_num / 2)
	{
		dst = mlx_data->addr + (pixel * (mlx_data->bits_per_pixel / 8));
		*(unsigned int*)dst = color->ceilling_color;
		pixel++;
	}
	while (pixel < pixels_num)
	{
		dst = mlx_data->addr + (pixel * (mlx_data->bits_per_pixel / 8));
		*(unsigned int*)dst = color->floor_color;
		pixel++;
	}
}

float	wall_distance(t_game_data *game, float angle)
{
	float	x_dist;
	float	y_dist;



}

void	throw_rays(t_game_data *game, t_mlx_data *mlx_data)
{
	float	step_alpha;
	int		i;
	float	dist;

	i = 0;
	step_alpha = ALPHA_DIF / (WIDTH / 2);
	while (i < (WIDTH / 2))
	{
		dist = wall_distance(game, game->alpa_player - ALPHA_DIF + step_alpha * i);
	}
}

void	drow_image(t_game_data *game_data, t_mlx_data *mlx_data, t_global *texturs)
{


	drow_back(mlx_data, game_data);
	throw_rays(game_data, mlx_data);





	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img, 0, 0);
}