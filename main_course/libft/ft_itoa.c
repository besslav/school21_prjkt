/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:53:17 by pskip             #+#    #+#             */
/*   Updated: 2021/10/15 12:59:27 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_revclon(char *str, char *pre, int n)
{
	int	endind;

	endind = 0;
	if (pre[0] == '-')
	{
		endind = 1;
		str[0] = '-';
		str++;
	}
	while (--n >= endind)
		*str++ = pre[n];
	*str = '\0';
}

char	*ft_itoa(int n)
{
	int		lenn;
	char	*str;
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
	str = (char *)malloc((lenn + 1) * sizeof(char));
	if (str)
		ft_revclon (str, pre, lenn);
	return (str);
}
