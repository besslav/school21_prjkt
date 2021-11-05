/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:57:23 by pskip             #+#    #+#             */
/*   Updated: 2021/10/28 21:28:43 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_put_uns_nbr_fd(unsigned int n);
int	ft_put_16x_nbr_fd(int n);
int	ft_put_16Xx_nbr_fd(int n);
int	ft_putpointe_fd(unsigned long long int print_it);
int	ft_putnbr_fd(int n);
int	ft_putstr(char *s);
int	ft_putchar(int s);

#endif