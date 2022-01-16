/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:53:11 by pskip             #+#    #+#             */
/*   Updated: 2022/01/15 22:29:41 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	norna_for_rotater(t_stack *push_it)
{
	if (push_it->a_steps > 0 && push_it->b_steps > 0
		&& push_it->b_dir == push_it->a_dir)
		return (1);
	return (0);
}

void	rotater(t_meta *data, t_stack *push_it)
{
	while (norna_for_rotater(push_it))
	{
		if (push_it->b_dir == 1)
			rr(data);
		else if (push_it->b_dir == -1)
			rrr(data);
		push_it->a_steps--;
		push_it->b_steps--;
	}
	while (push_it->a_steps > 0)
	{
		if (push_it->a_dir == 1)
			r_ab(data, 'a');
		else if (push_it->a_dir == -1)
			rr_ab(data, 'a');
		push_it->a_steps--;
	}
	while (push_it->b_steps > 0)
	{
		if (push_it->b_dir == 1)
			r_ab(data, 'b');
		else if (push_it->b_dir == -1)
			rr_ab(data, 'b');
		push_it->b_steps--;
	}
}

void	algo_continue(t_meta *data)
{
	t_stack	*push_it;

	while (data->b)
	{
		push_it = algo_base(data);
		rotater(data, push_it);
		pa(data);
	}
	if (data->a->real_ind <= data->a_size / 2)
		while (data->a->real_ind != 0)
			rr_ab(data, 'a');
	else
		while (data->a->real_ind != 0)
			r_ab(data, 'a');
	clean_all(data);
}