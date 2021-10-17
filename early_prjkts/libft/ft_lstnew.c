/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:48:03 by pskip             #+#    #+#             */
/*   Updated: 2021/10/16 16:48:05 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*begin;

	begin = (t_list *)malloc(sizeof(t_list));
	if (begin == NULL)
		return (NULL);
	begin->content = content;
	begin->next = NULL;
	return (begin);
}
