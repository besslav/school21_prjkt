/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:48:03 by pskip             #+#    #+#             */
/*   Updated: 2022/01/26 20:56:23 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*begin;

	begin = (t_stack *)malloc(sizeof(t_stack));
	if (begin == NULL)
		exit (EXIT_FAILURE);
	begin->content = content;
	begin->next = begin;
	begin->prev = begin;
	begin->combo_prev = begin;
	begin->best_combo = 1;
	begin->a_steps = 0;
	begin->b_steps = 0;
	begin->a_best_steps = -1;
	begin->b_best_steps = -1;
	return (begin);
}

void	init_stack(int *mass, int *sorted, t_meta *data)
{
	int		ind;
	t_stack	*a_start;

	ind = 0;
	data->a = ft_lstnew(mass[0]);
	data->a->real_ind = find_ind(data->a->content, sorted);
	a_start = data->a;
	while (++ind < data->len)
	{
		data->a->next = ft_lstnew(mass[ind]);
		data->a->next->prev = data->a;
		data->a = data->a->next;
		data->a->real_ind = find_ind(data->a->content, sorted);
	}
	data->a->next = a_start;
	a_start = data->a;
	data->a = data->a->next;
	data->a->prev = a_start;
	data->b = NULL;
}
