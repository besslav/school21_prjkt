/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:50:33 by pskip             #+#    #+#             */
/*   Updated: 2021/11/29 15:20:48 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strlen(const char *string)
// len of string
{
	int	lenstring;

	if (!string)
		return (-1);
	lenstring = 0;
	while (string[lenstring] != '\0')
		lenstring++;
	return (lenstring);
}

int	ft_putstr(char *s, t_list data)
{
	int		ind;
	int		strlen;
	int		ans;

	if (!s)
		s = "(null)";
	strlen = ft_strlen(s);
	if (data.accuracy < strlen && data.accuracy != -1)
		strlen = data.accuracy;
	ans = 0;
	ind = -1;
	while (data.minus == 0 && ans < (data.width - strlen))
		ans += write(1, &data.zero, 1);
	while (s[++ind] && (ind < data.accuracy || data.accuracy == -1))
		ans += write(1, &s[ind], 1);
	while (ans < data.width && data.minus == 1)
		ans += write(1, &data.zero, 1);
	return (ans);
}

int	ft_putchar(int s, t_list data)
{
	int		ans;

	ans = 0;
	if (data.width == 0)
		data.width = 1;
	if (data.minus == 1)
	{
		write (1, &s, 1);
		ans++;
	}
	while (ans < (data.width - (1 - data.minus)))
	{
		write(1, &data.zero, 1);
		ans++;
	}
	if (data.minus == 0)
	{
		write (1, &s, 1);
		ans++;
	}
	return (ans);
}
