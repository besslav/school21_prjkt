/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:45:06 by pskip             #+#    #+#             */
/*   Updated: 2021/10/17 16:47:13 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			lens;
	unsigned int	ind;

	if (s && f)
	{
		lens = ft_strlen(s);
		ind = 0;
		while (s[ind])
		{
			f(ind, (s + ind));
			ind++;
		}
	}
}
