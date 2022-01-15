/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:38:03 by pskip             #+#    #+#             */
/*   Updated: 2022/01/15 22:33:09 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	step_mass_creator(char **pre_mass, int *step_mass)
{
	int	j;

	j = -1;
	while (pre_mass[++j])
	{
		isnum(pre_mass[j]);
		step_mass[j] = ft_atoi(pre_mass[j]);
	}
}

int	*init_mass(int ac, char **av, t_meta *data, int len)
{
	char	**pre_mass;
	int		*step_mass;
	int		i;
	int		*mass;

	i = 1;
	mass = (int *)malloc(sizeof(int));
	if (!mass)
		exit (EXIT_FAILURE);
	while (i < ac)
	{
		pre_mass = ft_split(av[i++], ' ');
		if (!pre_mass)
			exit (EXIT_FAILURE);
		len = ft_numslen(pre_mass);
		step_mass = (int *)malloc(len * sizeof(int));
		if (!step_mass)
			exit (EXIT_FAILURE);
		step_mass_creator(pre_mass, step_mass);
		cleaner(pre_mass, len);
		mass = ft_strjoin(mass, step_mass, data->len, len);
		data->len += len;
	}
	return (mass);
}

int	push_swap(int ac, char **av)
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
	sorted(mass, data->len);
	sort_mass = numcpy(mass, data->len);
	quick(sort_mass, 0, data->len);
	check_doubles(sort_mass, data->len);
	init_stack(mass, sort_mass, data);
	free(sort_mass);
	free(mass);
	data->a_size = data->len;
	algo_start(data);
	return (1);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
}
