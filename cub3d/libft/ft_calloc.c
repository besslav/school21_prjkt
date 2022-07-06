/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:33:47 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:33:50 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	i;

	i = 0;
	pointer = malloc (count * size);
	if (pointer == (void *)0)
		return (pointer);
	while (i < count * size)
	{
		((char *)pointer)[i] = '\0';
		i++;
	}
	return (pointer);
}
