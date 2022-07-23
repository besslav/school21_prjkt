/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drow_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:00:46 by pskip             #+#    #+#             */
/*   Updated: 2022/07/23 16:17:28 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		is_wall_mini(int x, int y, t_game_data *game)
{
	float	x_pos;
	float	y_pos;

	x_pos = game->x_player - 2.5 + (0.05 * x);
	y_pos = game->y_player - 2.5 + (0.05 * y);
	if (x_pos >= 0 && y_pos >= 0 && x_pos < game->x_len && y_pos < game->y_len)
	{
		if (game->map[array_pos((int)x_pos, (int)y_pos, game->x_len)] == '1')
			return (1);		
	}
	return (0);
}

void	drow_minimap(t_all_data *all_data)
{
	int	x;
	int	y;

	y = -1;
	while( ++y < 100)
	{
		x = -1;
		while (++x < 100)
		{
			if (is_wall_mini(x, y, all_data->game_data))
				put_pixel(x, y, all_data->screen_img_data, newcolor(0, 0, 0));
			else
				put_pixel(x, y, all_data->screen_img_data, newcolor(255, 255, 255));
		}
		
	}
}