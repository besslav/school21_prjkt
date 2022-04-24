/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:47:35 by pskip             #+#    #+#             */
/*   Updated: 2022/03/22 12:47:36 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	long int		ans;

	ans = 0;
	i = 0;
	sign = 1;
	if (*(str + i) == '-')
	{
		sign = sign * -1;
		i++;
	}
	if (*(str + i) == '+' && sign != -1)
		i++;
	while ((*(str + i) >= '0') && (*(str + i) <= '9'))
	{
		ans = (ans * 10) + (*(str + i) - 48);
		i++;
		if (ans < -2147483648 || ans > 2147483647)
		{
			write(2, "its too big, sempai\n", 20);
			return (0);
		}
	}
	return ((int)ans * sign);
}
