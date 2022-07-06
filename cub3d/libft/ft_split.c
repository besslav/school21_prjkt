/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:31 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:36:32 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static char	**free_split(char ***words, int k)
{
	while (k > 0)
	{
		free((*words)[k]);
		k--;
	}
	free(*words);
	return ((char **)(void **)0);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	copy_word(char const *s, char c, char *word)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**w;

	if (!s)
		return ((char **)(void **)0);
	w = (char **)malloc((words_count(s, c) + 1) * sizeof(char *));
	if (!w)
		return (w);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			w[k] = (char *)malloc((word_len(&(s[i]), c) + 1) * sizeof(char));
			if (!w[k])
				return (free_split(&w, k));
			i += copy_word(&(s[i]), c, w[k++]);
		}
	}
	w[k] = (char *)(void *)0;
	return (w);
}
