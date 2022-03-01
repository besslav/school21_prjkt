/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:36:06 by pskip             #+#    #+#             */
/*   Updated: 2021/10/11 17:48:54 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
// len of string
{
	size_t	lenstring;

	lenstring = 0;
	while (string[lenstring] != '\0')
		lenstring++;
	return (lenstring);
}
