#include "push_swap.h"
#include <stdio.h>

static t_stack	*find_min(t_meta *data)
{
	t_stack *check;
	t_stack *min;

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
	t_stack *check;
	t_stack *max;

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
		r_ab(data, 'a');
		return ;
	}
	if (data->a->real_ind > data->a->next->real_ind && data->a->real_ind > data->a->prev->real_ind)
		r_ab(data, 'a');
	if (data->a->next->real_ind > data->a->real_ind && data->a->next->real_ind > data->a->prev->real_ind)
		rr_ab(data, 'a');
	if (data->a->real_ind > data->a->next->real_ind)
		sa(data, 1);

}

void	algo3_5(t_meta *data)
{
	t_stack *min;
	t_stack *max;

	if (data->a_size <= 3)
		algo3(data);
	if (data->a_size > 3)
	{
		min = find_min(data);
		max = find_max(data);
		while (data->b_size != 2)
		{
			if (data->a == min || data->a == max)
				pb(data);
			else
				r_ab(data, 'a');
		}
		algo3(data);
		pa(data);
		if (data->a == max)
			rr_ab(data, 'a');
		pa(data);
		if (data->a == max)
			rr_ab(data, 'a');
	}
}