/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:08:11 by pskip             #+#    #+#             */
/*   Updated: 2021/07/30 23:08:15 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>
#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int			*ans;
	long int	i;

	i = max - min;
	if (i <= 0)
		return (NULL);
	ans = malloc(4 * i);
	i--;
	while (i >= 0)
	{
		ans[i] = max - 1;
		i--;
		max--;
	}
	return (ans);
}
/*int	main(void)
{
	int i;
	//char i[] = "asdfg";
	int *ans;
	i = 0;
	ans = ft_range(-40,9);
	while (i < 49)
	{
		printf("%d", ans[i]);
		i++;
	}
}*/
