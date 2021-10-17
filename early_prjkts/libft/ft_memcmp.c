/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:12 by pskip             #+#    #+#             */
/*   Updated: 2021/10/13 16:07:19 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *first, const void *second, size_t end)
/* сравнивает первые end символов массивов, на которые указывают 
	first и second ans return ascii diff*/
{
	size_t				ind;
	unsigned char		*fir;
	unsigned char		*sec;

	ind = 0;
	fir = (unsigned char *) first;
	sec = (unsigned char *) second;
	while (ind < end)
	{
		if (fir[ind] != sec[ind])
			return (fir[ind] - sec[ind]);
		ind++;
	}
	return (0);
}
