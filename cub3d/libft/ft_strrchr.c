/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:37:30 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:37:31 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*chr;

	str = (char *)s;
	chr = (char *)(void *)0;
	while (*str != '\0')
	{
		if (*str == (char)c)
			chr = str;
		str++;
	}
	if (c == '\0')
		return (str);
	return (chr);
}
