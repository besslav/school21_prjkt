/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:43:52 by pskip             #+#    #+#             */
/*   Updated: 2022/01/25 15:55:29 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*news;
	int		ind;

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

char	*ft_substr(char const *s, int start, int len)
{
	char	*save;
	int		ind;

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

int	ft_strncmp(const char *first, const char *second, int end)
/* finf first diff between two str and return ascii diff,
	 no more then (end) checks*/
{
	int				ind;
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

int	ft_strlen(const char *string)
// len of string
{
	size_t	lenstring;

	lenstring = 0;
	while (string[lenstring] != '\0')
		lenstring++;
	return (lenstring);
}