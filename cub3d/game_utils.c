/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:33:56 by pskip             #+#    #+#             */
/*   Updated: 2022/07/13 16:33:47 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	array_pos(int x, int y, int x_len)
{
	return(y * x_len + x);
}

void	put_pixel(int x, int y, t_img_data *img_data, int color)
{
	char	*dst;
	
	if (x >=0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img_data->addr + (y * img_data->line_length + x * (img_data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}
