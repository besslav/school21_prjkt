/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:51:09 by pskip             #+#    #+#             */
/*   Updated: 2021/10/16 16:51:10 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (*lst && new)
	{
		elem = ft_lstlast(*lst);
		elem->next = new;
	}
	else if (new)
		*lst = new;
}
