/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:40:25 by pskip             #+#    #+#             */
/*   Updated: 2022/01/15 22:24:59 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_best_way_continue(t_stack *elem, int a_size, int b_size)
{
	int	a_rev;
	int	b_rev;

	a_rev = 0;
	b_rev = 0;
	if (elem->a_steps != 0)
		a_rev = a_size - elem->a_steps;
	if (elem->b_steps != 0)
		b_rev = b_size - elem->b_steps;
	if (elem->a_steps + b_rev < elem->best_sum)
	{
		elem->b_dir = -1;
		elem->a_dir = 1;
		elem->b_best_steps = b_rev;
		elem->a_best_steps = elem->a_steps;
		elem->best_sum = elem->a_steps + b_rev;
	}
	if (a_rev + elem->b_steps < elem->best_sum)
	{
		elem->a_dir = -1;
		elem->b_dir = 1;
		elem->a_best_steps = a_rev;
		elem->b_best_steps = elem->b_steps;
		elem->best_sum = a_rev + elem->b_steps;
	}
}

static void	find_best_way(t_stack *elem, int a_size, int b_size)
{
	int	neg_way;
	int	a_rev;
	int	b_rev;

	a_rev = 0;
	b_rev = 0;
	if (elem->a_steps != 0)
		a_rev = a_size - elem->a_steps;
	if (elem->b_steps != 0)
		b_rev = b_size - elem->b_steps;
	neg_way = b_rev;
	if (a_rev > b_rev)
		neg_way = a_rev;
	if (neg_way < elem->best_sum)
	{
		elem->a_dir = -1;
		elem->b_dir = -1;
		elem->a_best_steps = a_rev;
		elem->b_best_steps = b_rev;
		elem->best_sum = neg_way;
	}
	find_best_way_continue(elem, a_size, b_size);
}

static void	count_steps_in_a(t_stack *elem, t_stack *a)
{
	if (norma_adapt(elem, a))
	{
		elem->a_steps = 0;
		elem->a_dir = 0;
	}
	else
	{
		elem->a_dir = 1;
		elem->a_steps = 0;
		while (!(norma_adapt(elem, a)))
		{
			elem->a_steps++;
			a = a->next;
		}
	}
}

static void	count_all_steps(t_meta *data, t_stack *on_count)
{
	t_stack	*start;

	on_count->b_dir = 0;
	ground_zero(on_count);
	start = on_count;
	count_steps_in_a(on_count, data->a);
	on_count->best_sum = on_count->b_steps;
	if (on_count->a_steps >= on_count->b_steps)
		on_count->best_sum = on_count->a_steps;
	find_best_way(on_count, data->a_size, data->b_size);
	on_count = on_count->next;
	while (on_count != start)
	{
		ground_zero(on_count);
		on_count->b_steps = on_count->prev->b_steps + 1;
		on_count->b_dir = 1;
		count_steps_in_a(on_count, data->a);
		on_count->best_sum = on_count->b_steps;
		if (on_count->a_steps >= on_count->b_steps)
			on_count->best_sum = on_count->a_steps;
		find_best_way(on_count, data->a_size, data->b_size);
		on_count = on_count->next;
	}
}

t_stack	*algo_base(t_meta *data)
{
	t_stack	*on_count;
	t_stack	*for_push;

	on_count = data->b;
	count_all_steps(data, on_count);
	read_best_sum(on_count);
	for_push = on_count;
	on_count = on_count->next;
	while (on_count != data->b)
	{
		read_best_sum(on_count);
		if (on_count->best_sum < for_push->best_sum)
			for_push = on_count;
		on_count = on_count->next;
	}
	return (for_push);
}

//./a.out -10 5 7 0 34 35 64 -7 -6 -8 13 20 15 -15