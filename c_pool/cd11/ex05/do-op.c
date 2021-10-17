/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:10:09 by pskip             #+#    #+#             */
/*   Updated: 2021/08/04 23:10:11 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "opers.h"

int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	errors(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[2][i])
		i++;
	if (argc != 4)
		return (1);
	if (i != 1)
	{
		write(1, "0\n", 2);
		return (1);
	}
	if ((argv[2][0] != '%') && (argv[2][0] != '*') && (argv[2][0] != '+')
		&& (argv[2][0] != '-') && (argv[2][0] != '/'))
	{
		write(1, "0\n", 2);
		return (1);
	}
	return (0);
}

int	creator(char **argv, int a, int b)
{
	int		((*operations[5])(int, int));

	operations[0] = &add;
	operations[1] = &minus;
	operations[2] = &multi;
	operations[3] = &div;
	operations[4] = &mod;
	if (argv[2][0] == '+')
		return (add(a, b));
	if (argv[2][0] == '-')
		return (minus(a, b));
	if (argv[2][0] == '*')
		return (multi(a, b));
	if ((argv[2][0] == '/') && (b != 0))
		return (div(a, b));
	if ((argv[2][0] == '%') && (b != 0))
		return (mod(a, b));
	return (0);
}

int	main(int argc, char **argv)
{
	int		ans;
	int		a;
	int		b;

	if (errors(argc, argv))
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if ((argv[2][0] == '/') && (b == 0))
	{
		write (1, "Stop : division by zero\n", 24);
		return (0);
	}
	if ((argv[2][0] == '%') && (b == 0))
	{
		write (1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_putnbr(creator(argv, a, b));
	write(1, "\n", 1);
	return (0);
}
