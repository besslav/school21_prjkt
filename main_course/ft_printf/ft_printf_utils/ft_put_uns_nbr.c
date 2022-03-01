/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:00:20 by pskip             #+#    #+#             */
/*   Updated: 2021/11/27 22:26:50 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_uns_nbr(unsigned int n, t_list data)
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
	return (ft_print_num(pre, lenn, data));
}

int	ft_put_16x_nbr(unsigned int n, t_list data)
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
	return (ft_print_num(pre, lenn, data));
}

int	ft_put_16Xx_nbr(unsigned int n, t_list data)
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
	return (ft_print_num(pre, lenn, data));
}

int	ft_putpointer(unsigned long long int n, t_list data)
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
	data.extra = 'x';
	data.extra_len = 2;
	return (ft_print_num(pre, lenn, data));
}
