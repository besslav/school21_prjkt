/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:53:55 by pskip             #+#    #+#             */
/*   Updated: 2022/03/10 04:09:19 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	newcolor(int r, int g, int b)
{
	return (((0xFF & (r)) << 16) | ((0xFF & (g)) << 8) | (0xFF & (b)));
}

int	get_r(int trgb)
{
	return ((trgb & 0xFF0000) >> 16);
}

int	get_g(int trgb)
{
	return ((trgb & 0xFF00) >> 8);
}

int	get_b(int trgb)
{
	return (trgb & 0x0000FF);
}

unsigned int	get_a_color_gap(int start, int end, unsigned char slider)
{
	unsigned int	result;
	int				red;
	int				green;
	int				blue;

	red = get_r(end) - get_r(start);
	green = get_g(end) - get_g(start);
	blue = get_b(end) - get_b(start);
	result = start + newcolor((int)((double)red / 256 * slider),
			(int)((double)green / 256 * slider),
			(int)((double)blue / 256 * slider));
	return (result);
}
