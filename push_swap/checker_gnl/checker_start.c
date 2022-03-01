/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:54:19 by pskip             #+#    #+#             */
/*   Updated: 2022/03/01 18:20:30 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_stack_sorted(t_meta *data)
{
	t_stack *check;
	if (data->b)
		return (0);
	check = data->a->next;
	while(check != data->a)
	{
		if (check->content < check->prev->content)
			return (0);
		check = check->next;
	}
	return (1);
}

static int	ft_strcmp(const char *first, const char *second)
/* finf first diff between two str and return ascii diff,
	 no more then (end) checks*/
{
	size_t	ind;

	ind = 0;

	while ((first[ind] || second[ind]))
	{
		if (first[ind] != second[ind])
			return (first[ind] - second[ind]);
		ind++;
	}
	return (0);
}

static void do_command(char *line, t_meta *data)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(data, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(data, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(data, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(data, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(data, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		r_ab(data, 'a', 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		r_ab(data, 'b', 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(data, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rr_ab(data, 'a', 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rr_ab(data, 'b', 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(data, 0);
	else
		write(1, "unknown command\n", 16);
}

static void	checker_start(t_meta *data)
{
	char	*command;


	command = get_next_line(0);
	while (command)
	{
		do_command(command, data);
		free(command);
		command = get_next_line(0);
	}
	if (command)
		free(command);
	if (is_stack_sorted(data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	// функция для проверки успешности основного проекта
	t_meta	*data;
	int		*mass;

	if (ac < 2)
		exit (EXIT_FAILURE);
	data = (t_meta *)malloc(sizeof(t_meta));
	data->len = 0;
	mass = init_mass(ac, av, data, 0);
	if (!mass)
		exit(EXIT_FAILURE);
	check_doubles(mass, data->len);
	sorted(mass, data->len);
	init_stack(mass, mass, data);
	free(mass);
	data->a_size = data->len;
	data->b_size = 0;
	checker_start(data);
}
