/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:43:52 by pskip             #+#    #+#             */
/*   Updated: 2021/10/14 18:43:59 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*news;
	size_t	ind;

	ind = 0;
	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	news = (char *)malloc(s1len + s2len + 1);
	if (news == NULL)
		return (NULL);
	while (ind < s1len)
	{
		news[ind] = s1[ind];
		ind++;
	}
	ind = -1;
	while (++ind < s2len)
		news[s1len + ind] = s2[ind];
	news[s1len + ind] = '\0';
	return (news);
}
