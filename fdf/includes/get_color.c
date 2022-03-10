/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:24:51 by pskip             #+#    #+#             */
/*   Updated: 2022/03/10 04:02:09 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	helper(char *elem, int i)
{
	int	color;
	int	len;

	color = 0;
	len = 0;
	while (elem[++i] && elem[i] != '\n')
	{
		len++;
		if (elem[i] >= '0' && elem[i] <= '9')
			color = color * 16 + (elem[i] - 48);
		else if (elem[i] >= 65 && elem[i] <= 70)
			color = color * 16 + (elem[i] - 55);
		else if (elem[i] >= 97 && elem[i] <= 102)
			color = color * 16 + (elem[i] - 87);
		else
			errors("bad symbol\n", 11);
		if (len > 8)
			errors("color_too_long\n", 15);
	}
	return (color);
}

int	get_color(char *elem)
{
	int				i;

	i = 0;
	while (elem[i])
	{
		if (elem[i] == ',')
		{
			i += 2;
			return (helper(elem, i));
		}
		else
			i++;
	}
	return (0);
}
