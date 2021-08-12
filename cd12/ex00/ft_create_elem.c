/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:13:07 by pskip             #+#    #+#             */
/*   Updated: 2021/08/05 22:13:10 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*begin;
	t_list	elem1;

	begin = (t_list *)malloc(sizeof(t_list));
	elem1.next = 0;
	elem1.data = data;
	*begin = elem1;
	return (begin);
}
