/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:20 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:36:22 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_put(int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	recursive_put(n / 10, fd);
	c = (char)((n % 10) * ((n > 0) * 2 - 1) + 48);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!fd)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	recursive_put(n, fd);
}
