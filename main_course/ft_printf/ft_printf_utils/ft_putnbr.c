/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:51:43 by pskip             #+#    #+#             */
/*   Updated: 2021/11/28 03:13:28 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n, t_list data)
{
	int		lenn;
	char	pre[11];
	int		sign;

	lenn = 0;
	sign = 1;
	if (n < 0)
	{
		data.extra = '-';
		data.extra_len = 1;
		sign = -1;
	}
	if (n == 0)
		pre[lenn++] = '0';
	while (n)
	{
		pre[lenn++] = ((n % 10) * sign) + 48;
		n = n / 10;
	}
	return (ft_print_num(pre, lenn, data));
}
