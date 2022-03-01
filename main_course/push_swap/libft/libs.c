/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:19:15 by pskip             #+#    #+#             */
/*   Updated: 2022/01/20 19:47:15 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*numcpy(int *sors, int len)
//copy from strfr to strto no more then n-1 symbol and add \0 to the end.
{
	int		ind;
	int		*sortit;

	ind = 0;
	sortit = (int *)malloc (sizeof(int) * len);
	while (ind < len)
	{
		sortit[ind] = sors[ind];
		ind++;
	}
	return (sortit);
}

int	ft_numslen(char **string)
// len of string
{
	int	lenstring;

	lenstring = 0;
	while (string[lenstring])
		lenstring++;
	return (lenstring);
}

int	ft_strlen(const char *string)
// len of string
{
	int	lenstring;

	lenstring = 0;
	while (string[lenstring] != '\0')
		lenstring++;
	return (lenstring);
}

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	long int		ans;

	ans = 0;
	i = 0;
	sign = 1;
	if (*(str + i) == '-')
	{
		sign = sign * -1;
		i++;
	}
	if (*(str + i) == '+' && sign != -1)
		i++;
	while ((*(str + i) >= '0') && (*(str + i) <= '9'))
	{
		ans = (ans * 10) + (*(str + i) - 48);
		i++;
		if (ans < -2147483648 || ans > 2147483647)
		{
			write(2, "its too big, sempai\n", 20);
			exit (EXIT_FAILURE);
		}
	}
	return ((int)ans * sign);
}

int	*ft_intjoin(int *s1, int *s2, int s1len, int s2len)
{
	int	*news;
	int	ind;

	ind = -1;
	if (!s1 || !s2)
		exit (EXIT_FAILURE);
	news = (int *)malloc((s1len + s2len) * sizeof(int));
	if (news == NULL)
		exit (EXIT_FAILURE);
	while (++ind < s1len)
		news[ind] = s1[ind];
	ind = -1;
	while (++ind < s2len)
		news[s1len + ind] = s2[ind];
	free(s1);
	free(s2);
	return (news);
}
