/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:50:40 by pskip             #+#    #+#             */
/*   Updated: 2021/10/17 16:50:40 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev_elem;
	t_list	*real_elem;

	if (lst && del)
	{
		real_elem = *lst;
		while (real_elem->next != NULL)
		{
			prev_elem = real_elem;
			real_elem = real_elem->next;
			(*del)(prev_elem->content);
			free(prev_elem);
		}
		(*del)(real_elem->content);
		free(real_elem);
		*lst = NULL;
	}
}
