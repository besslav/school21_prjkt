/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:51:43 by pskip             #+#    #+#             */
/*   Updated: 2021/10/15 18:37:25 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_revwr(char *pre, int n, int fd)
{
	int	endind;

	endind = 0;
	if (pre[0] == '-')
	{
		endind = 1;
		write(fd, "-", 1);
	}
	while (--n >= endind)
		write(fd, &pre[n], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		lenn;
	char	pre[11];
	int		sign;

	lenn = 0;
	sign = 1;
	if (fd <= 0)
		return ;
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
	ft_revwr(pre, lenn, fd);
}
