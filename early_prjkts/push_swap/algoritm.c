#include "push_swap.h"

static void	check_first(t_stack *start, int *best)
{
	t_stack	*in_check;
	t_stack	*check_prev;

	in_check = start->next;
	start->combo_len = 1;
	while (in_check != start)
	{
		in_check->combo_len = 1;
		check_prev = in_check->prev;
		while (check_prev != start->prev)
		{
			if (check_prev->real_ind < in_check->real_ind
				&& check_prev->combo_len >= in_check->combo_len)
			{
				in_check->combo_len = check_prev->combo_len + 1;
				in_check->combo_prev = check_prev;
				if (in_check->combo_len > in_check->best_combo)
					in_check->best_combo = in_check->combo_len;
			}
			check_prev = check_prev->prev;
		}
		in_check = in_check->next;
	}
	if (start->prev->best_combo > *best)
		*best = start->prev->best_combo;
}


static int	*find_best(t_meta *data)
{
	t_stack	*start;
	int		step_in_save;
	int		*save;

	start = data->a;

	data->len = 1;
	check_first(start, &data->len);
	start = start->next;
	while (start != data->a)
	{
		check_first(start, &data->len);
		start = start->next;
	}
	while(start->best_combo != data->len)
		start = start->next;
	check_first(start->next, &data->len);
	step_in_save = data->len - 1;
	save = (int *)malloc(data->len * sizeof(int));
	while (step_in_save >= 0)
	{
		save[step_in_save--] = start->real_ind;
		start = start->combo_prev;
	}
	return (save);
}

void	algo_start(t_meta *data)
{
	int		*a_save;
	t_stack	*break_point;
	int		all_len_save;

	all_len_save = data->len;
	data->a_size = all_len_save;
	a_save = find_best(data);
	data->b_size = 0;
	while (!check_if_elem_in_subcombo(a_save, data))
		pb(data);
	break_point = data->a;
	r_ab(data, 'a');
	while (data->a != break_point)
	{
		if (!check_if_elem_in_subcombo(a_save, data))
			pb(data);
		else
			r_ab(data, 'a');
	}
	free(a_save);
	algo_continue(data);
}