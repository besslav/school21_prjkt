/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:45:13 by ymaragre          #+#    #+#             */
/*   Updated: 2021/08/01 22:51:42 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	size_str(char *str);
int	count_word(char *str);

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		n;
	int		n_word;
	char	**arr_str;

	if (str[0] == 0)
		return (0);
	n_word = count_word(str);
	if (n_word == 0)
		return (0);
	arr_str = (char **) malloc((n_word) * sizeof(char *));
	if (arr_str == 0)
		return (0);
	i = 0;
	n = 0;
	while (n < n_word)
	{
		j = size_str(str + i);
		arr_str[n] = str + (i++);
		i += j;
		n++;
	}
	arr_str[n_word] = 0;
	return (arr_str);
}

int	count_word(char *str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		j = size_str(str + (i++));
		if (j == 0)
			return (0);
		i += j;
		n++;
	}
	return (n);
}

int	size_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}
