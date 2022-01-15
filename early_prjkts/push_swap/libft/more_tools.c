/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:18:52 by pskip             #+#    #+#             */
/*   Updated: 2022/01/15 17:32:19 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_ind(int num, int *sorted)
{
	int	ind;

	ind = 0;
	while (!(sorted[ind] == num))
		ind++;
	return (ind);
}

int	check_if_elem_in_subcombo(int *subcombo, t_meta *data)
{
	int	i;

	i = -1;
	while (++i < data->len)
	{
		if (data->a->real_ind == subcombo[i])
			return (1);
	}
	return (0);
}

void	read_best_sum(t_stack *on_count)
{
	if (on_count->b_best_steps != -1)
		on_count->b_steps = on_count->b_best_steps;
	if (on_count->a_best_steps != -1)
		on_count->a_steps = on_count->a_best_steps;
}

void	ground_zero(t_stack *on_count)
{
	on_count->a_best_steps = -1;
	on_count->b_best_steps = -1;
	on_count->a_steps = 0;
	on_count->b_steps = 0;
	on_count->best_sum = 0;
}

int	norma_adapt(t_stack *elem, t_stack *a)
{
	if (((a->real_ind > elem->real_ind
				&& a->prev->real_ind < elem->real_ind)
			|| (a->real_ind < a->prev->real_ind
				&& ((a->real_ind > elem->real_ind
						&& a->prev->real_ind > elem->real_ind)
					|| (a->real_ind < elem->real_ind
						&& a->prev->real_ind < elem->real_ind)))))
		return (1);
	return (0);
}
