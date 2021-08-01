/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:08:25 by pskip             #+#    #+#             */
/*   Updated: 2021/07/30 23:08:33 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	long int	i;
	int			ans;

	i = max - min;
	ans = max - min;
	if (i <= 0)
		return (0);
	range[0] = malloc(4 * i);
	i--;
	while (i >= 0)
	{
		range[0][i] = max - 1;
		i--;
		max--;
	}
	return (ans);
}

/*int	main(void)
{
	int i;
	//char i[] = "asdfg";
	int **ans;
	i = 0;
	i = ft_ultimate_range(ans, -40, 9);
	printf("%d", i);
}*/
