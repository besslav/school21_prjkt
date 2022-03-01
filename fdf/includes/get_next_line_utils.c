/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:02 by pskip             #+#    #+#             */
/*   Updated: 2022/03/01 20:37:24 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_strchr(char *str, int findit)
//finding first (findit) in (str)
{
	int	ind;

	ind = 0;
	findit = (char)findit;
	if (!str)
		return (0);
	while (str[ind])
	{
		if (str[ind] == findit)
			return ((char *)&str[ind]);
		ind++;
	}
	if (findit == '\0')
		return ((char *)&str[ind]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	char	*news;
	size_t	ind;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	ind = -1;
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	news = (char *)malloc((s1len + ft_strlen(s2) + 1) * sizeof(char));
	if (news == NULL)
		return (NULL);
	while (++ind < s1len)
		news[ind] = s1[ind];
	while (*s2)
		news[ind++] = *(s2++);
	news[ind] = '\0';
	free(s1);
	return (news);
}

char	*ft_substr_gnl(char const *s, int start, int len)
{
	char	*save;
	int	ind;

	ind = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		save = (char *)malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
		return (save);
	}
	save = (char *)malloc((len + 1) * sizeof(char));
	if (!save)
		return (NULL);
	while (ind < len)
	{
		save[ind] = s[start + ind];
		ind++;
	}
	save[ind] = '\0';
	return (save);
}
