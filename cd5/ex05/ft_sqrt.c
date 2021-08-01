/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 20:28:32 by pskip             #+#    #+#             */
/*   Updated: 2021/07/27 20:28:36 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int			i;
	int			max;
	long int	ii;

	if (nb < 1)
		return (0);
	max = (nb / 2) + 1;
	i = 1;
	while (i <= max)
	{
		ii = i * i;
		if (ii == nb)
			return (i);
		if (ii > nb)
			return (0);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(-5));
	printf("%d\n", ft_sqrt(625));
	printf("%d\n", ft_sqrt(2147483647));
}*/
