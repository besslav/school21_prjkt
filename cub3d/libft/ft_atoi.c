/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:33:32 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:33:34 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	process_the_number(const char *str, int z)
{
	int	num;
	int	old_num;
	int	counter;

	num = 0;
	counter = 0;
	while (*str >= '0' && *str <= '9')
	{
		old_num = num;
		num = num * 10;
		num = num + (*str - 48) * z;
		if ((num >= 0 && old_num < 0) || (num < 0 && old_num >= 0))
		{
			counter += z;
			if (counter == 8 || counter == -9)
				return (0 - (counter > 0));
		}
		str++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	z;

	z = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			z = z * (-1);
		str++;
	}
	return (process_the_number(str, z));
}
