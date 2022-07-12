/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drow_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:27:52 by pskip             #+#    #+#             */
/*   Updated: 2022/07/12 20:54:24 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drow_image(t_all_data *all_data)
{
	

	drow_back(all_data->mlx_data, all_data->game_data);
	throw_rays(all_data);





	mlx_put_image_to_window(all_data->mlx_data->mlx, all_data->mlx_data->win,
							all_data->mlx_data->img, 0, 0);
}