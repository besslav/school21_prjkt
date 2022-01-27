/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:43:52 by pskip             #+#    #+#             */
/*   Updated: 2022/01/27 16:34:32 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strlen(const char *string)
// len of string
{
	int	lenstring;

	lenstring = 0;
	while (string[lenstring] != '\0')
		lenstring++;
	return (lenstring);
}

char	*ft_strjoin(char *s1, char *s2)
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
	free(s1);
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

int	ft_strncmp(char *first, char *second, int end)
/* finf first diff between two str and return ascii diff,
	 no more then (end) checks*/
{
	int	ind;

	ind = 0;
	if (end == 0)
		return (0);
	while (second[ind] && ind < end)
	{
		if (first[ind] != second[ind])
			return (first[ind] - second[ind]);
		ind++;
	}
	if (first[ind] && first[ind] == '\n')
		return (0);
	else
		return (first[ind]);
}

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
