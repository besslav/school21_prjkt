/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:27 by pskip             #+#    #+#             */
/*   Updated: 2021/10/11 18:21:21 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
/* Функция memmove() копирует n символов из массива,
 на который указывает strfr, в мас­сив, на который указывает strto.
 Если массивы перекрываются, копирование производится корректно.*/
{
	int				ind;
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *) src;
	to = (unsigned char *) dest;
	ind = 0;
	if (from == to || n == 0)
		return (dest);
	if ((src == 0) && (dest == 0))
		return (0);
	if (to > from && to - from < (int)n)
	{
		ind = (int)(n - 1);
		while (ind >= 0)
		{
			to[ind] = from[ind];
			ind--;
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
