/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:36:26 by pskip             #+#    #+#             */
/*   Updated: 2021/10/11 17:44:49 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, char findit)
//finding last (findit) in (str)
{
	int		ind;
	int		ans;

	ind = 0;
	ans = -1;
	while (str[ind])
	{
		if (str[ind] == findit)
			ans = ind;
		ind++;
	}
	if (ans != -1)
		return (&str[ans]);
	if (findit == '\0')
		return (&str[ind]);
	return (0);
}
