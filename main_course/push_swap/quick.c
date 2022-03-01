/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:20:55 by pskip             #+#    #+#             */
/*   Updated: 2022/01/10 21:20:56 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	quick(int *mass, int start, int end)
{
	int	save;
	int	ind;
	int	real_end;

	if (start >= end)
		return ;
	real_end = end;
	end--;
	ind = start + 1;
	while (ind <= end)
	{
		if (mass[ind] > mass[start])
		{
			save = mass[ind];
			mass[ind] = mass[end];
			mass[end--] = save;
		}
		else
			ind++;
	}
	save = mass[ind - 1];
	mass[ind - 1] = mass[start];
	mass[start] = save;
	quick(mass, start, ind - 1);
	quick(mass, ind, real_end);
}
