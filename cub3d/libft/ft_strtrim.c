/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:37:36 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:37:38 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char a, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static char	*set_not_found_exception(char const *s1)
{
	size_t	i;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	p = (char *)malloc((i + 1) * sizeof(char));
	if (!p)
		return (p);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	*trim_all_exception(void)
{
	char	*p;

	p = (char *)malloc(sizeof(char));
	if (!p)
		return (p);
	p[0] = '\0';
	return (p);
}

static char	*save_trimmed_str(char const *s1, size_t len, size_t i)
{
	char	*p;
	size_t	j;

	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (p);
	j = 0;
	while (j < len)
	{
		p[j] = s1[i + j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return ((char *)(s1));
	if (!set)
		return (set_not_found_exception(s1));
	i = 0;
	while (s1[i] && isinset(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (trim_all_exception());
	j = i;
	while (s1[j])
		j++;
	j -= 1;
	while (isinset(s1[j], set))
		j--;
	return (save_trimmed_str(s1, j - i + 1, i));
}
