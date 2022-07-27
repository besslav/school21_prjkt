/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:34:40 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:34:41 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zero_exception(void)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * 2);
	if (!p)
		return (p);
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		num;
	int		len;
	char	*p;

	len = 0;
	num = n;
	while (num != 0 && ++len)
		num = num / 10;
	len = len + (n < 0);
	if (len == 0)
		return (zero_exception());
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (p);
	p[len] = '\0';
	if (n < 0)
		p[0] = '-';
	while (n != 0)
	{
		len--;
		p[len] = ((n > 0) * 2 - 1) * (n % 10) + '0';
		n = n / 10;
	}
	return (p);
}
