/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:35:40 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:35:41 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ss1;
	char	*ss2;

	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while (n > 1 && *(unsigned char *)ss1 == *(unsigned char *)ss2)
	{
		ss1++;
		ss2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((int)(*(unsigned char *)ss1 - *(unsigned char *)ss2));
}
