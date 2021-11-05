/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:18:47 by pskip             #+#    #+#             */
/*   Updated: 2021/10/28 21:42:02 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switch_mod(const char *str, int ind, va_list args)
{
	if (str[ind] == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (str[ind] == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (str[ind] == 'p')
		return (ft_putpointe_fd(va_arg(args, unsigned long long int)));
	if ((str[ind] == 'd') || str[ind] == 'i')
		return (ft_putnbr_fd(va_arg(args, int)));
	if (str[ind] == 'u')
		return (ft_put_uns_nbr_fd(va_arg(args, unsigned int)));
	if (str[ind] == 'x')
		return (ft_put_16x_nbr_fd(va_arg(args, int)));
	if (str[ind] == 'X')
		return (ft_put_16Xx_nbr_fd(va_arg(args, int)));
	if (str[ind] == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		ind;
	int		count;

	ind = -1;
	count = 0;
	va_start(argptr, str);
	while (str[++ind])
	{
		if (str[ind] != '%')
			count += write(1, &str[ind], 1);
		else
			count += switch_mod(str, ++ind, argptr);
	}
	va_end(argptr);
	return (count);
}

/*  int	main(void)
{
	//gcc ft_printf.c ft_printf.h ft_printf_utils/ *
	int p;
	int p2;
	int b = -2147483648;
	unsigned int	b2 = 4294967295;
	p =  printf("aaa%c %%,	(%s), digit : (%d),uns_dig : (%u), 16x : (%x), 16X : (%X), pointer : (%p)\n", 'b', (void*)0, b, b2, b2, b2,&b);
 p2 = ft_printf("aaa%c %%,	(%s), digit : (%d),uns_dig : (%u), 16x : (%x), 16X : (%X), pointer : (%p)\n", 'b', (void*)0, b, b2, b2, b2, &b);
	printf("print : %d; ft_print : %d", p, p2);
}  */
