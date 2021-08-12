/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:14:55 by pskip             #+#    #+#             */
/*   Updated: 2021/08/05 22:14:57 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	elem;
	t_list	*ans;

	elem = *begin_list;
	while (elem.next != 0)
	{
		elem = *elem.next;
	}
	ans = &elem;
	return (ans);
}
