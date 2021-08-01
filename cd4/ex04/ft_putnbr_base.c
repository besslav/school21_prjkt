/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:22:10 by pskip             #+#    #+#             */
/*   Updated: 2021/07/27 14:22:18 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_base_legal(char *base)
{
	int		i;
	int		past;

	i = 0;
	past = 0;
	while (*(base + i))
	{
		if ((*(base + i) < '0') || (*(base + i) > 'z')
			|| ((*(base + i) > '9') && (*(base + i) < 'A'))
			|| ((*(base + i) > 'Z') && (*(base + i) < 'a')))
			return (0);
		while (past < i)
		{
			if (*(base + i) == *(base + past))
				return (0);
			past++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	printer(char *base, int *out, int pto)
{
	int	midl;

	while (pto >= 0)
	{
		midl = out[pto];
		write(1, &base[midl], 1);
		pto--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		pto;
	int		out[255];
	int		kostil;

	kostil = 1;
	pto = -1;
	len = is_base_legal(base);
	if (len != 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			kostil = -1;
		}
		if (nbr == 0)
			write(1, "0", 1);
		while (nbr != 0)
		{
			pto++;
			out[pto] = (nbr % len) * kostil;
			nbr = (nbr / len);
		}
		printer(base, out, pto);
	}
}

/*int main(void)
{
	char base[] = "012345@6789";
 	char *p1;
 	p1 = base;
 	ft_putnbr_base(-45, p1);
 	write(1,"\n", 1);
 	ft_putnbr_base(-2147483648, p1);
 	write(1,"\n", 1);
 	ft_putnbr_base(2147483647, p1);
 	write(1,"\n", 1);
 	ft_putnbr_base(45, p1);
 	write(1,"\n", 1);
 	ft_putnbr_base(0, p1);
}*/
