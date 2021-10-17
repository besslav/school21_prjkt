/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:07:11 by pskip             #+#    #+#             */
/*   Updated: 2021/07/30 23:07:20 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>
#include <stdlib.h>
char	*ft_strdup(char *str)
{
	char	*ans;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (NULL);
	ans = malloc(1 * i);
	i = 0;
	while (str[i])
	{
		ans[i] = str[i];
		i++;
	}
	return (ans);
}

/*int	main(void)
{
	char i[] = "asdfg";
	char *ans;
	ans = ft_strdup(i);
	printf("%s\n", ans);
}*/
