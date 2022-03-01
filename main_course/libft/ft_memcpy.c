/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:21 by pskip             #+#    #+#             */
/*   Updated: 2021/10/11 17:56:54 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *strto, const void *strfr, size_t n)
/* Функция memcpy() копирует n символов из массива,
 на который указывает strfr, в массив, на который указывает strtoo.
 Если массивы перекрываются, поведение memcpy() не определено.*/
{
	const char	*first;
	char		*second;
	size_t		i;

	i = 0;
	first = strfr;
	second = strto;
	if ((strfr == 0) && (strto == 0))
		return (0);
	while (i < n)
	{
		second[i] = first[i];
		i++;
	}
	return (strto);
}
