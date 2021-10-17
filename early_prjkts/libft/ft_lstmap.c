/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:49:08 by pskip             #+#    #+#             */
/*   Updated: 2021/10/17 16:51:56 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*start;

	if (lst && del)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (!new_elem)
			return (NULL);
		start = new_elem;
		while (lst->next)
		{
			lst = lst->next;
			new_elem = ft_lstnew((*f)(lst->content));
			if (!new_elem)
			{
				ft_lstclear(&start, del);
				return (NULL);
			}
			ft_lstadd_back(&start, new_elem);
		}
		return (start);
	}
	return (NULL);
}
