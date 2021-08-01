/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:20:21 by pskip             #+#    #+#             */
/*   Updated: 2021/07/27 19:20:24 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

/*int main(void)
{
	printf("%d\n", ft_fibonacci(5));
	printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(2));
	printf("%d\n", ft_fibonacci(-3));
	printf("%d\n", ft_fibonacci(10));
}*/
