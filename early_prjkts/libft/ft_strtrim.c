/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:34:45 by pskip             #+#    #+#             */
/*   Updated: 2021/10/14 18:38:38 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	inset(char c1, char const *set)
{
	size_t	indset;

	indset = 0;
	while (set[indset])
	{
		if (c1 == set[indset])
			return (1);
		indset++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	inds1;
	size_t	indans;
	size_t	lenans;
	char	*str;

	inds1 = 0;
	indans = 0;
	if (!s1 || !set)
		return (0);
	lenans = ft_strlen(s1);
	if (lenans != 0)
	{
		while (lenans && inset(s1[lenans - 1], set))
			lenans--;
		while (lenans && inset(s1[inds1], set))
			inds1++;
	}
	str = (char *)malloc(lenans - inds1 + 1);
	if (str)
	{
		while (inds1 < lenans)
			str[indans++] = s1[inds1++];
		str[indans] = '\0';
	}
	return (str);
}
