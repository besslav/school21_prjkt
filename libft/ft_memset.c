/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:33 by pskip             #+#    #+#             */
/*   Updated: 2021/10/11 17:51:37 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memset(char *str, int upd, size_t n)
// changing first (n) elems from (str) on (upd) and return new (str)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		str[i] = (char)upd;
		i++;
	}
	return (str);
}
