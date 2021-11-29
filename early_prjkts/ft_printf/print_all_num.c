/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:59:09 by pskip             #+#    #+#             */
/*   Updated: 2021/11/29 14:59:11 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	extra_print(t_list data, char *pre, int len)
{
	if (data.sharp == 1 && pre[0] == '0' && len == 1)
		return (0);
	if (data.extra_len == 2)
		write(1, "0", 1);
	write(1, &data.extra, 1);
	return (data.extra_len);
}

static int	no_minus_f(t_list data, char *pre, int len)
{
	int	ans;

	ans = 0;
	if (data.extra != '0' && data.zero == '0')
		extra_print(data, pre, len);
	while ((data.width - ans) > (data.accuracy + data.extra_len)
		&& (data.width - ans) > (len + data.extra_len))
		ans += write (1, &data.zero, 1);
	if (data.extra != '0' && data.zero != '0')
		extra_print(data, pre, len);
	while (data.accuracy-- > len && data.accuracy != -1)
		ans += write(1, "0", 1);
	while (--len >= 0)
		ans += write(1, &pre[len], 1);
	if (data.extra != '0')
		ans += data.extra_len;
	return (ans);
}

static int	with_minus_f(t_list data, char *pre, int len)
{
	int	ans;

	ans = 0;
	if (data.extra != '0')
		ans += extra_print(data, pre, len);
	while (data.accuracy-- > len)
		ans += write(1, "0", 1);
	while (--len >= 0)
		ans += write(1, &pre[len], 1);
	while (data.width > ans)
		ans += write(1, " ", 1);
	return (ans);
}

int	ft_print_num(char *pre, int len, t_list data)
{
	if (data.sharp == 1 && pre[0] == '0' && len == 1)
		data.extra_len = 0;
	if (data.accuracy == 0 && ((pre[0] == '0' && len == 1) || !pre))
	{
		pre = "";
		len = 0;
	}
	if (data.minus == 0)
		return (no_minus_f(data, pre, len));
	else
		return (with_minus_f(data, pre, len));
}
