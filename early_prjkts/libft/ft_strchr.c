/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:39 by pskip             #+#    #+#             */
/*   Updated: 2021/10/17 16:25:48 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *str, int findit)
//finding first (findit) in (str)
{
	int	ind;

	ind = 0;
	findit = (char)findit;
	while (str[ind])
	{
		if (str[ind] == findit)
			return (&str[ind]);
		ind++;
	}
	if (findit == '\0')
		return (&str[ind]);
	return (0);
}
