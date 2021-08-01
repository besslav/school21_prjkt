/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:00:59 by pskip             #+#    #+#             */
/*   Updated: 2021/07/27 15:01:10 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*int main(void)
{
	printf("%d", ft_recursive_factorial(5));
	printf("%d", ft_recursive_factorial(1));
	printf("%d", ft_recursive_factorial(0));
	printf("%d", ft_recursive_factorial(-5));
}*/
