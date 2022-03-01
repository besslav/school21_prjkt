/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mass_initer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:48:12 by pskip             #+#    #+#             */
/*   Updated: 2022/01/20 20:49:19 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	step_mass_creator(char **pre_mass, int *step_mass)
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
		mass = ft_intjoin(mass, step_mass, data->len, len);
		data->len += len;
	}
	return (mass);
}