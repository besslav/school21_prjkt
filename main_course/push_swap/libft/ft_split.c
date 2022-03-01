/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:49:53 by pskip             #+#    #+#             */
/*   Updated: 2022/01/20 20:05:26 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_substr(char const *s, int start, int len)
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
	save = (char *)malloc((len + 1) * sizeof(char));
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

static int	n_words(char const *s, char c)
{
	int	s_ind;
	int	words;

	words = 0;
	if (s[0] != c)
		words++;
	s_ind = 1;
	while (s[s_ind])
	{
		if (s[s_ind] != c && s[s_ind - 1] == c)
			words++;
		s_ind++;
	}
	return (words);
}

static int	wlen(char const *s, int start, char c)
{
	int	ind;

	ind = 0;
	while (s[start + ind] && s[start + ind] != c)
		ind++;
	return (ind);
}

static char	**ft_split_cont(char const *s, char c, char	**ans)
{
	int		ans_ind;
	int		s_ind;
	int		w_len;

	s_ind = 0;
	ans_ind = 0;
	while (s[s_ind])
	{
		if (s[s_ind] == c)
			s_ind++;
		else
		{
			w_len = wlen(s, s_ind, c);
			ans[ans_ind] = ft_substr(s, s_ind, w_len);
			if (ans[ans_ind] == NULL)
			{
				cleaner(ans, ans_ind);
				return (NULL);
			}
			s_ind += w_len;
			ans_ind++;
		}
	}
	ans[ans_ind] = NULL;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ans;

	if (!s)
		return (0);
	words = n_words(s, c);
	ans = (char **) malloc((words + 1) * sizeof(char *));
	if (!ans)
		return (NULL);
	return (ft_split_cont(s, c, ans));
}
