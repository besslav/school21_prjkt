/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:33:35 by pskip             #+#    #+#             */
/*   Updated: 2021/10/14 18:34:34 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*save;
	size_t	ind;

	ind = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		save = (char *)malloc(1);
		save[0] = '\0';
		return (save);
	}
	save = (char *)malloc(len + 1);
	if (save)
	{
		while (ind < len)
		{
			save[ind] = s[start + ind];
			ind++;
		}
		save[ind] = '\0';
	}
	return (save);
}
