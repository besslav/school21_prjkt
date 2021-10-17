/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 20:35:58 by pskip             #+#    #+#             */
/*   Updated: 2021/07/29 20:36:01 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	row;
	int	col;

	col = argc - 1;
	while (col > 0)
	{
		row = 0;
		while (argv[col][row])
		{
			write(1, &argv[col][row], 1);
			row++;
		}	
		write(1, "\n", 1);
		col--;
	}
}
