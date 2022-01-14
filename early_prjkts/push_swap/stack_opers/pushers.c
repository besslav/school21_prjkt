/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:18:28 by pskip             #+#    #+#             */
/*   Updated: 2022/01/13 15:51:25 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*del_one(t_stack *stack)
{
	stack->prev->next = stack->next;
	stack->next->prev = stack->prev;
	stack = stack->next;
	return (stack);
}

static t_stack	*add_one(t_stack *stack, t_stack *save)
{
	save->next = stack;
	save->prev = stack->prev;
	stack->prev->next = save;
	stack->prev = save;
	stack = save;
	return (stack);
}

void	pa(t_meta *data)
{
	t_stack	*save;

	if (data->b)
	{
		save = data->b;
		if (data->b->next == data->b)
			data->b = NULL;
		else
			data->b = del_one(data->b);
		data->b_size--;
		if (data->a)
			data->a = add_one(data->a, save);
		else
		{
			data->a = ft_lstnew(save->content);
			data->a->real_ind = save->real_ind;
		}
		data->a_size++;
		write(1, "pa\n", 3);
	}
}

void	pb(t_meta *data)
{
	t_stack	*save;

	if (data->a)
	{
		save = data->a;
		if (data->a->next == data->a)
			data->a = NULL;
		else
			data->a = del_one(data->a);
		data->a_size--;
		if (data->b)
			data->b = add_one(data->b, save);
		else
		{
			data->b = ft_lstnew(save->content);
			data->b->real_ind = save->real_ind;
		}
		data->b_size++;
		write(1, "pb\n", 3);
	}
}
