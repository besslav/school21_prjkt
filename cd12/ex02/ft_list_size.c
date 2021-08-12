/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:14:20 by pskip             #+#    #+#             */
/*   Updated: 2021/08/05 22:14:24 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	elem;
	int		i;

	if (!begin_list)
		return (0);
	elem = *begin_list;
	i = 1;
	while (elem.next != 0)
	{
		i++;
		elem = *elem.next;
	}
	return (i);
}
