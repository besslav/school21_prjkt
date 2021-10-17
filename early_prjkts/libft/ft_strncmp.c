/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:36:14 by pskip             #+#    #+#             */
/*   Updated: 2021/10/13 17:57:28 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t end)
/* finf first diff between two str and return ascii diff,
	 no more then (end) checks*/
{
	size_t			ind;
	unsigned char	*fir;
	unsigned char	*sec;

	ind = 0;
	fir = (unsigned char *) first;
	sec = (unsigned char *) second;
	if (end == 0)
		return (0);
	while (ind < end && (first[ind] || second[ind]))
	{
		if (first[ind] != second[ind])
			return (fir[ind] - sec[ind]);
		ind++;
	}
	return (0);
}
