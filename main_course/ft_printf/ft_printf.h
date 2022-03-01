/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:57:23 by pskip             #+#    #+#             */
/*   Updated: 2021/11/29 15:03:17 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int			width;
	int			accuracy;
	int			minus;
	char		zero;
	int			new_ind;
	int			ans_len;
	int			extra_len;
	char		extra;
	int			sharp;
	int			space;
	int			plus;
}	t_list;

int		ft_printf(const char *str, ...);
t_list	flag_bilder(const char *str, int ind, t_list arg_data);
int		ft_print_num(char *pre, int len, t_list data);
int		ft_put_uns_nbr(unsigned int n, t_list data);
int		ft_put_16x_nbr(unsigned int n, t_list data);
int		ft_put_16Xx_nbr(unsigned int n, t_list data);
int		ft_putpointer(unsigned long long int print_it, t_list data);
int		ft_putnbr(int n, t_list data);
int		ft_putstr(char *s, t_list data);
int		ft_putchar(int s, t_list data);

#endif