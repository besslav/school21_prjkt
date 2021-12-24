/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:48:03 by pskip             #+#    #+#             */
/*   Updated: 2021/12/11 13:09:05 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int *content)
{
	t_stack	*begin;

	begin = (t_stack *)malloc(sizeof(t_stack));
	if (begin == NULL)
		return (NULL);
	begin->content = content;
	begin->next = begin;
	begin->prev = begin;
	return (begin);
}

void	ft_lstadd_front(t_stack *lst, t_stack *new)
{
	lst->prev->next = new;
	new->next = lst;
}

void	ft_lstadd_back(t_stack *lst, t_stack *new)
{
	new->next = lst;
	new->prev = lst->prev;
	lst = new;
}

int	ft_lstsize(t_stack *lst)
{
	int		list_len;
	t_stack	*start;

	start = lst;
	if (lst == lst->next)
		return (1);
	list_len = 1;
	lst = lst->next;
	while (lst != start)
	{
		list_len++;
		lst = lst->next;
	}
	return (list_len);
}

t_meta	*init_stack(int ac, char **av)
{
	
}