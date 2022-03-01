/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:36:00 by pskip             #+#    #+#             */
/*   Updated: 2021/10/14 18:39:53 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *strto, const char *strfr, size_t n)
//copy from strfr to strto no more then n-1 symbol and add \0 to the end.
{
	size_t		ind;

	if (n <= 0)
		return (ft_strlen(strfr));
	ind = 0;
	n--;
	while (strfr[ind] && (ind < n))
	{
		strto[ind] = strfr[ind];
		ind++;
	}
	strto[ind] = '\0';
	return (ft_strlen(strfr));
}
