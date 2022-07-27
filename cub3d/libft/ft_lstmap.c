/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:35:17 by pskip             #+#    #+#             */
/*   Updated: 2022/06/23 16:35:18 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_lstmap(t_list *new_lst, void (*del)(void *))
{
	t_list	*old_elem;

	while (new_lst)
	{
		old_elem = new_lst;
		new_lst = new_lst -> next;
		del(old_elem -> content);
		free(old_elem);
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*old_elem;
	t_list	*new_elem;

	if (!lst)
		return (lst);
	old_elem = (t_list *)(void *)0;
	while (lst)
	{
		new_elem = (t_list *)malloc(sizeof(t_list));
		if (!new_elem)
			return (free_lstmap(new_lst, del));
		new_elem -> content = f(lst -> content);
		new_elem -> next = (t_list *)(void *)0;
		if (!old_elem)
			new_lst = new_elem;
		else
			old_elem -> next = new_elem;
		old_elem = new_elem;
		lst = lst -> next;
	}
	return (new_lst);
}
