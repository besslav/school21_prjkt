/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:05:43 by pskip             #+#    #+#             */
/*   Updated: 2021/11/29 15:06:08 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	rebild(t_list data, char mod)
{
	if (data.plus == 1 )
		data.space = 0;
	if ((mod == 'd' || mod == 'i') && data.accuracy > data.width)
		data.minus = 0;
	if (data.plus == 1 && (mod == 'd' || mod == 'i') && data.extra != '-')
		data.extra = '+';
	if (data.space == 1 && (mod == 'd' || mod == 'i') && data.extra != '-')
		data.extra = ' ';
	if (data.minus == 1)
		data.zero = ' ';
	if (data.accuracy < data.width && data.accuracy != -1
		&& mod != 'c' && mod != 's')
		data.zero = ' ';
	if (data.extra != '0')
		data.extra_len = 1;
	if (data.sharp == 1 && (mod == 'x' || mod == 'X'))
		data.extra_len = 2;
	if (data.sharp == 1 && (mod == 'x' || mod == 'X'))
		data.extra = mod;
	else
		data.sharp = 0;
	return (data);
}

static int	end_of_flaf(char flag)
{
	char	*dict;
	int		ind_in_d;

	dict = "cspdiuxX123456789.%%";
	ind_in_d = 0;
	while (ind_in_d < 19)
	{
		if (dict[ind_in_d] == flag)
			return (1);
		ind_in_d++;
	}
	return (0);
}

static t_list	width_counter(const char *str, int ind, t_list arg_data)
{
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		arg_data.width = (arg_data.width * 10) + (str[ind] - 48);
		ind++;
	}
	arg_data.new_ind = ind;
	return (arg_data);
}

static t_list	accuracy_counter(const char *str, t_list arg_data)
{
	int	ind;

	ind = arg_data.new_ind + 1;
	arg_data.accuracy = 0;
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		arg_data.accuracy = (arg_data.accuracy * 10) + (str[ind] - 48);
		ind++;
	}
	arg_data.new_ind = ind;
	return (arg_data);
}

t_list	flag_bilder(const char *str, int ind, t_list arg_data)
{
	while (str[ind] && !(end_of_flaf(str[ind])))
	{
		if (str[ind] == '0')
			arg_data.zero = '0';
		if (str[ind] == '-')
			arg_data.minus = 1;
		if (str[ind] == '#')
			arg_data.sharp = 1;
		if (str[ind] == '+')
			arg_data.plus = 1;
		if (str[ind] == ' ')
			arg_data.space = 1;
		ind++;
	}
	arg_data = width_counter(str, ind, arg_data);
	if (str[arg_data.new_ind] == '.')
		arg_data = accuracy_counter(str, arg_data);
	arg_data = rebild(arg_data, str[arg_data.new_ind]);
	return (arg_data);
}
