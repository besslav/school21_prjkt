/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:15:25 by pskip             #+#    #+#             */
/*   Updated: 2021/08/05 22:15:27 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*ans;

	elem->next = *begin_list;
	while (elem->next != 0)
	{
		elem = elem->next;
	}
	ans = ft_create_elem(data);
	elem->next = ans;
}
