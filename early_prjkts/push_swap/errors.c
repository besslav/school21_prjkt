/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:21:04 by pskip             #+#    #+#             */
/*   Updated: 2022/01/10 22:26:06 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnum(char *num)
{
	int	i;

	i = -1;
	while (num[++i])
	{
		if (num[i] < '0' || num[i] > '9')
			if (!(i == 0 && (num[i] == '-' || num[i] == '+')))
				exit(0);
	}
	return (1);
}

void	check_doubles(int *mass, int len)
{
	int	i;

	i = 0;
	while (++i < len - 1)
	{
		if (mass[i] == mass[i - 1] || mass[i] == mass[i + 1])
		{
			write(2, "doubles detected\n", 17);
			exit(0);
		}
	}
}

void	sorted(int *mass, int len)
{
	int	ind;

	ind = -1;
	if (len == 1)
	{
		write(1, "one elem\n", 9);
		exit(0);
	}
	while (++ind < len - 1)
		if (mass[ind] > mass[ind + 1])
			return ;
	write(1, "already sorted\n", 15);
	exit(0);
}
