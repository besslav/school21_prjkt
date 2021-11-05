/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:50:33 by pskip             #+#    #+#             */
/*   Updated: 2021/10/28 21:40:18 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		count += write(1, "(null)", 6);
	else
	{
		while (s[i])
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	return (count);
}

int	ft_putchar(int s)
{
	return (write(1, &s, 1));
}
