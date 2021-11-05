/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:51:43 by pskip             #+#    #+#             */
/*   Updated: 2021/10/28 21:40:41 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_revwr(char *pre, int n)
{
	int	endind;

	endind = 0;
	if (pre[0] == '-')
	{
		endind = 1;
		write(1, "-", 1);
	}
	while (--n >= endind)
		write(1, &pre[n], 1);
}

int	ft_putnbr_fd(int n)
{
	int		lenn;
	char	pre[11];
	int		sign;

	lenn = 0;
	sign = 1;
	if (n < 0)
	{
		pre[lenn++] = '-';
		sign = -1;
	}
	if (n == 0)
		pre[lenn++] = '0';
	while (n)
	{
		pre[lenn++] = ((n % 10) * sign) + 48;
		n = n / 10;
	}
	ft_revwr(pre, lenn);
	return (lenn);
}
