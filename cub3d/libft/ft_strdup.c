/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:41 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:36:43 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s2;
	unsigned long	size;

	size = 0;
	while (s1[size])
		size++;
	s2 = (char *)malloc(size + 1);
	if (s2)
	{
		size = 0;
		while (s1[size])
		{
			s2[size] = s1[size];
			size++;
		}
		s2[size] = '\0';
	}
	return (s2);
}
