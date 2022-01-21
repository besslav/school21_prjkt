/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_3_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:49:58 by pskip             #+#    #+#             */
/*   Updated: 2022/01/21 17:47:02 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


static t_stack	*find_min(t_meta *data)
{
	t_stack	*check;
	t_stack	*min;

	check = data->a->next;
	min = data->a;
	while (check != data->a)
	{
		if (check->real_ind < min->real_ind)
			min = check;
		check = check->next;
	}
	return (min);
}

static t_stack	*find_max(t_meta *data)
{
	t_stack	*check;
	t_stack	*max;

	check = data->a->next;
	max = data->a;
	while (check != data->a)
	{
		if (check->real_ind > max->real_ind)
			max = check;
		check = check->next;
	}
	return (max);
}

static void	algo3(t_meta *data)
{
	if (data->a_size == 2)
	{
		r_ab(data, 'a', 1);
		return ;
	}
	if (data->a->real_ind > data->a->next->real_ind
		&& data->a->real_ind > data->a->prev->real_ind)
		r_ab(data, 'a', 1);
	if (data->a->next->real_ind > data->a->real_ind
		&& data->a->next->real_ind > data->a->prev->real_ind)
		rr_ab(data, 'a', 1);
	if (data->a->real_ind > data->a->next->real_ind)
		sa(data, 1);
}

void	algo3_5(t_meta *data)
{
	t_stack	*min;
	t_stack	*max;

	if (data->a_size <= 3)
		algo3(data);
	if (data->a_size > 3)
	{
		min = find_min(data);
		max = find_max(data);
		while (data->b_size != 2)
		{
			if (data->a == min || data->a == max)
				pb(data, 1);
			else
				r_ab(data, 'a', 1);
		}
		algo3(data);
		pa(data, 1);
		if (data->a->content == max->content)
			r_ab(data, 'a', 1);
		pa(data, 1);
		if (data->a->content == max->content)
			r_ab(data, 'a', 1);
	}
}
