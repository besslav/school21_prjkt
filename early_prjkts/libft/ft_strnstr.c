/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:36:20 by pskip             #+#    #+#             */
/*   Updated: 2021/10/17 17:03:34 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
//find substr little in big (len elem of big)
{
	size_t	b;
	size_t	l;
	size_t	lenl;

	b = 0;
	l = 0;
	lenl = ft_strlen(little);
	if (lenl == 0)
		return ((char *)&big[b]);
	if (big && little && *big && *little)
	{
		while (b + lenl <= len)
		{
			if ((big[b + l] == little[l]) && little[l])
				l++;
			else
			{
				if (!little[l])
					return ((char *)&big[b]);
				l = 0;
				b++;
			}
		}
	}
	return (0);
}
