/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:22:21 by pskip             #+#    #+#             */
/*   Updated: 2022/07/31 22:20:33 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_color_len(char **color)
{
	int	i;

	i = 0;
	while (color && color[i])
		i++;
	if (i != 3)
		error("color_line_bad\n");
}

int	len_file_way(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' '
		&& str[i] != '\t')
		i++;
	return (i);
}
