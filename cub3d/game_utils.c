/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:33:56 by pskip             #+#    #+#             */
/*   Updated: 2022/07/12 17:21:32 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	array_pos(int x, int y, int x_len)
{
	return(y * x_len + x);
}

void	put_pixel(int pixel, t_mlx_data *mlx_data, int color)
{
	char	*dst;
	
	dst = mlx_data->addr + (pixel * (mlx_data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
