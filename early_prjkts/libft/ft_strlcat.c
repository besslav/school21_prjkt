/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:53 by pskip             #+#    #+#             */
/*   Updated: 2021/10/11 17:49:33 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *strto, char *strfr, size_t n)
//copy from strfr to end of strto no more then n-1 symbol and add \0 to the end.
{
	size_t		ind;
	int			from;
	size_t		lento;

	from = 0;
	lento = ft_strlen(strto);
	ind = lento;
	if (lento > n)
		lento = n;
	while (strfr[from] && (ind + 1 < n))
	{
		strto[ind] = strfr[from];
		ind++;
		from++;
	}
	strto[ind] = '\0';
	return (ft_strlen(strfr) + lento);
}
