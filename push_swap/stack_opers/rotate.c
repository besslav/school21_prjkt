/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:17:49 by pskip             #+#    #+#             */
/*   Updated: 2022/01/21 17:32:19 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_ab(t_meta *data, char stack, int should_write)
{
	if (stack == 'a')
	{
		data->a = data->a->next;
		if (should_write)
			write(1, "ra\n", 3);
	}
	else
	{
		data->b = data->b->next;
		if (should_write)
			write(1, "rb\n", 3);
	}
}

void	rr(t_meta *data, int should_write)
{
	data->a = data->a->next;
	data->b = data->b->next;
	if (should_write)
		write(1, "rr\n", 3);
}

void	rr_ab(t_meta *data, char stack, int should_write)
{
	if (stack == 'a')
	{
		data->a = data->a->prev;
		if (should_write)
			write(1, "rra\n", 4);
	}
	else
	{
		data->b = data->b->prev;
		if (should_write)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_meta *data, int should_write)
{
	data->a = data->a->prev;
	data->b = data->b->prev;
	if (should_write)
		write(1, "rrr\n", 4);
}
