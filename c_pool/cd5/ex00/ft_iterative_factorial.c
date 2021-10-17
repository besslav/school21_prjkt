/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:27:41 by pskip             #+#    #+#             */
/*   Updated: 2021/07/27 15:27:46 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	ans;

	ans = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		ans = ans * nb;
		nb--;
	}
	return (ans);
}

/*int main(void)
{
	printf("%d",ft_iterative_factorial(5));
	printf("%d",ft_iterative_factorial(1));
	printf("%d",ft_iterative_factorial(0));
	printf("%d",ft_iterative_factorial(-5));
	return (0);
}*/
