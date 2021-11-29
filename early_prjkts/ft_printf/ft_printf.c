/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:04:20 by pskip             #+#    #+#             */
/*   Updated: 2021/11/29 16:23:28 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switch_mod(const char *str, va_list args, t_list arg_data)
{
	if (str[arg_data.new_ind] == 'c')
		return (ft_putchar(va_arg(args, int), arg_data));
	if (str[arg_data.new_ind] == 's')
		return (ft_putstr(va_arg(args, char *), arg_data));
	if (str[arg_data.new_ind] == 'p')
		return (ft_putpointer(va_arg(args, unsigned long long int), arg_data));
	if ((str[arg_data.new_ind] == 'd') || str[arg_data.new_ind] == 'i')
		return (ft_putnbr(va_arg(args, int), arg_data));
	if (str[arg_data.new_ind] == 'u')
		return (ft_put_uns_nbr(va_arg(args, unsigned int), arg_data));
	if (str[arg_data.new_ind] == 'x')
		return (ft_put_16x_nbr(va_arg(args, unsigned int), arg_data));
	if (str[arg_data.new_ind] == 'X')
		return (ft_put_16Xx_nbr(va_arg(args, unsigned int), arg_data));
	if (str[arg_data.new_ind] == '%')
		return (ft_putchar('%', arg_data));
	return (0);
}

static t_list	ft_print_arg(const char *str, int ind, va_list args)
{
	t_list	arg_data;

	arg_data.width = 0;
	arg_data.accuracy = -1;
	arg_data.zero = ' ';
	arg_data.minus = 0;
	arg_data.extra_len = 0;
	arg_data.extra = '0';
	arg_data.sharp = 0;
	arg_data.plus = 0;
	arg_data.space = 0;
	arg_data = flag_bilder(str, ind, arg_data);
	arg_data.ans_len = switch_mod(str, args, arg_data);
	return (arg_data);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		ind;
	int		count;
	t_list	data;

	ind = -1;
	count = 0;
	va_start(argptr, str);
	while (str[++ind])
	{
		if (str[ind] != '%')
			count += write(1, &str[ind], 1);
		else
		{
			data = ft_print_arg(str, ++ind, argptr);
			count += data.ans_len;
			ind = data.new_ind;
		}
	}
	va_end(argptr);
	return (count);
}
