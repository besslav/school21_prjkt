/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wall_drow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:51:18 by pskip             #+#    #+#             */
/*   Updated: 2022/07/12 17:20:57 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drow_line_of_wall(int h_wall, int x, t_mlx_data *mlx_data)
{
	int	i;
	int	y_start;
	
	i = 0;
	y_start = (HEIGHT - h_wall) / 2;
	while (i < h_wall)
	{
		put_pixel((WIDTH * (y_start + i) + x), mlx_data, newcolor(100,50,100));
		i++;
	}
}
