/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:39:27 by pskip             #+#    #+#             */
/*   Updated: 2021/10/17 16:46:54 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			lens;
	char			*str;
	unsigned int	ind;

	if (!s)
		return (0);
	lens = ft_strlen(s);
	str = (char *)malloc((lens + 1) * sizeof(char));
	if (str && f)
	{
		ind = 0;
		while (s[ind])
		{
			str[ind] = f(ind, s[ind]);
			ind++;
		}
		str[ind] = '\0';
	}
	return (str);
}
