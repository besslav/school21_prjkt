/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:17:09 by pskip             #+#    #+#             */
/*   Updated: 2022/01/21 17:32:17 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_meta *data, int check)
{
	if (data->a && data->a->next != data->a)
	{
		data->a->prev->next = data->a->next;
		data->a->next->next->prev = data->a;
		data->a->next->prev = data->a->prev;
		data->a->prev = data->a->next;
		data->a->next = data->a->prev->next;
		data->a->prev->next = data->a;
		data->a = data->a->prev;
		if (check)
			write(1, "sa\n", 3);
	}
}

void	sb(t_meta *data, int check)
{
	if (data->b && data->b->next != data->b)
	{
		data->b->prev->next = data->b->next;
		data->b->next->next->prev = data->b;
		data->b->next->prev = data->b->prev;
		data->b->prev = data->b->next;
		data->b->next = data->b->prev->next;
		data->b->prev->next = data->b;
		data->b = data->b->prev;
		if (check)
			write(1, "sb\n", 3);
	}
}

void	ss(t_meta *data, int should_write)
{
	sa(data, 0);
	sb(data, 0);
	if (should_write)
		write(1, "ss\n", 3);
}
