/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:33:32 by pskip             #+#    #+#             */
/*   Updated: 2022/07/31 20:12:53 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		ans;

	ans = 0;
	i = 0;
	sign = 1;
	if ((*(str + i) == '-') || (*(str + i) == '+'))
	{	
		if (*(str + i) == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_lib("atoi_error_bad_num\n");
		ans = (ans * 10) + (*(str + i) - 48);
		i++;
	}
	return (ans * sign);
}
