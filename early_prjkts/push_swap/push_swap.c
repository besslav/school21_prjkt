/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:38:03 by pskip             #+#    #+#             */
/*   Updated: 2022/01/20 20:49:11 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_meta	*data;
	int		*mass;
	int		*sort_mass;

	if (ac < 2)
		exit (EXIT_FAILURE);
	data = (t_meta *)malloc(sizeof(t_meta));
	data->len = 0;
	mass = init_mass(ac, av, data, 0);
	if (!mass)
		exit(EXIT_FAILURE);
	check_doubles(mass, data->len);
	sorted(mass, data->len);
	sort_mass = numcpy(mass, data->len);
	quick(sort_mass, 0, data->len);
	init_stack(mass, sort_mass, data);
	free(sort_mass);
	free(mass);
	data->a_size = data->len;
	algo_start(data);
	return (1);
}
// ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
