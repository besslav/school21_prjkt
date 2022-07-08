/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:50:50 by pskip             #+#    #+#             */
/*   Updated: 2022/07/08 17:29:25 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		newcolor(int r, int g, int b)
{
	return (((0xFF & (r)) << 16) | ((0xFF & (g)) << 8) | (0xFF & (b)));
}

void	pars_colors_line(t_global *data, t_game_data *game)
{
	char	**splited_color_line;
	int		int_line[3];
	int		i;

	splited_color_line = ft_split(data->ceilling, ',');
	i = -1;
	while(++i < 3)
		int_line[i] = ft_atoi(splited_color_line[i]);
	game->ceilling_color = newcolor(int_line[0], int_line[1], int_line[2]);
	cleaner(splited_color_line);
	splited_color_line = ft_split(data->floor, ',');
	i = -1;
	while(++i < 3)
		int_line[i] = ft_atoi(splited_color_line[i]);
	game->floor_color = newcolor(int_line[0], int_line[1], int_line[2]);
	cleaner(splited_color_line);




}