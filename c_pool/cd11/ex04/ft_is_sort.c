/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:12:39 by pskip             #+#    #+#             */
/*   Updated: 2021/08/04 23:12:41 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	toone(int i)
{
	if (i > 0)
		return (1);
	if (i < 0)
		return (-1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	last;
	int	now;

	i = 1;
	last = 0;
	while (tab[i])
	{
		now = toone((*f)(tab[i - 1], tab[i]));
		if (now && (last == 0))
		{
			last = now;
		}
		else if (!((now == 0) || (now == last)))
			return (0);
		i++;
	}
	return (1);
}
