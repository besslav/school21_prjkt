/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 20:35:43 by pskip             #+#    #+#             */
/*   Updated: 2021/07/29 20:35:47 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	row;
	int	col;

	col = 1;
	while (col < argc)
	{
		row = 0;
		while (argv[col][row])
		{
			write(1, &argv[col][row], 1);
			row++;
		}	
		write(1, "\n", 1);
		col++;
	}
}
