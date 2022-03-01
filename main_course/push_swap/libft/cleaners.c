/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:25:37 by pskip             #+#    #+#             */
/*   Updated: 2022/01/15 22:34:12 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cleaner(char **cleanit, int ind)
{
	while (ind >= 0)
		free(cleanit[ind--]);
	free(cleanit);
}

void	clean_all(t_meta *data)
{
	t_stack	*on_del;
	t_stack	*next;

	on_del = data->a->next;
	while (on_del != data->a)
	{
		next = on_del->next;
		free(on_del);
		on_del = next;
	}
	free(data->a);
	free(data);
}
