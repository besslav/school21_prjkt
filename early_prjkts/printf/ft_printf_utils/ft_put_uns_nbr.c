/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:00:20 by pskip             #+#    #+#             */
/*   Updated: 2021/10/28 21:32:41 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_rev_unswr(char *pre, int n)
{
	int	endind;

	endind = 0;
	while (--n >= endind)
		write(1, &pre[n], 1);
}

int	ft_put_uns_nbr_fd(unsigned int n)
{
	int		lenn;
	char	pre[10];

	lenn = 0;
	if (n == 0)
		pre[lenn++] = '0';
	while (n)
	{
		pre[lenn++] = (n % 10) + 48;
		n = n / 10;
	}
	ft_rev_unswr(pre, lenn);
	return (lenn);
}

int	ft_put_16x_nbr_fd(unsigned int n)
{
	int		lenn;
	char	pre[11];
	char	*dict;

	dict = "0123456789abcdef";
	lenn = 0;
	if (n == 0)
		pre[lenn++] = '0';
	while (n)
	{
		pre[lenn++] = dict[(n % 16)];
		n = n / 16;
	}
	ft_rev_unswr(pre, lenn);
	return (lenn);
}

int	ft_put_16Xx_nbr_fd(unsigned int n)
{
	int		lenn;
	char	pre[11];
	char	*dict;

	dict = "0123456789ABCDEF";
	lenn = 0;
	if (n == 0)
		pre[lenn++] = '0';
	while (n)
	{
		pre[lenn++] = dict[(n % 16)];
		n = n / 16;
	}
	ft_rev_unswr(pre, lenn);
	return (lenn);
}

int	ft_putpointe_fd(unsigned long long int n)
{
	int		lenn;
	char	pre[20];
	char	*dict;

	dict = "0123456789abcdef";
	lenn = 0;
	if (n == 0)
		pre[lenn++] = '0';
	while (n)
	{
		pre[lenn++] = dict[(n % 16)];
		n = n / 16;
	}
	write(1, "0x", 2);
	ft_rev_unswr(pre, lenn);
	return (lenn + 2);
}
