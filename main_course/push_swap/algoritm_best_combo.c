/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_best_combo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:34:49 by pskip             #+#    #+#             */
/*   Updated: 2022/03/01 18:18:40 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_rb(t_meta *data)
{
	pb(data, 1);
	if (data->b->real_ind < (data->a_size + data->b_size) / 2)
		r_ab(data, 'b', 1);
}

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
	while (start->best_combo != data->len)
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
	// поиск наибольшей отсортированной подпоследовательности
	int		*a_save;
	t_stack	*break_point;

	data->b_size = 0;
	if (data->a_size <= 5)
	{
		algo3_5(data);
		return ;
	}
	a_save = find_best(data);
	// переброска из а в b всех элементов не входящих
	// в наибольшую отсортированную подпоследовательность
	while (!check_if_elem_in_subcombo(a_save, data))
		pb_rb(data);
	break_point = data->a;
	r_ab(data, 'a', 1);
	while (data->a != break_point)
	{
		if (!check_if_elem_in_subcombo(a_save, data))
			pb_rb(data);
		else
			r_ab(data, 'a', 1);
	}
	free(a_save);
	algo_continue(data);
}
