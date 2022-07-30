/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:31 by pskip             #+#    #+#             */
/*   Updated: 2022/07/30 17:07:28 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	cleaner(char **cleanit, int ind)
{
	while (ind <= 0)
	{
		ind--;
		free(cleanit[ind]);
	}
	free(cleanit);
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
