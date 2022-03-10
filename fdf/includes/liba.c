/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:51:39 by pskip             #+#    #+#             */
/*   Updated: 2022/03/07 19:51:40 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_numslen(char **string)
// count words
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

void	cleaner(char **cleanit, int ind)
{
	while (ind >= 0)
		free(cleanit[ind--]);
	free(cleanit);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
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
