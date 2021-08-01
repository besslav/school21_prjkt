/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:15:59 by pskip             #+#    #+#             */
/*   Updated: 2021/07/27 16:16:03 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, (power - 1)));
}

/*int main(void)
{
	printf("%d\n", ft_recursive_power(5, 4));
	printf("%d\n", ft_recursive_power(-5, 3));
	printf("%d\n", ft_recursive_power(0, 0));
	printf("%d\n", ft_recursive_power(5, -3));
	printf("%d\n", ft_recursive_power(5, 0));
}*/
