/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:34:45 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:34:46 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		elem = *lst;
		while (elem -> next)
			elem = elem -> next;
		elem -> next = new;
	}
}
