/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:30:08 by pskip             #+#    #+#             */
/*   Updated: 2021/07/31 22:30:13 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
# define EVEN_MSG "I have an even number of arguments."
# define ODD_MSG  "I have an odd number of arguments."
# define SUCCESS  0
# define TRUE  1
# define FALSE  0
# define EVEN(x) (x % 2) - 1
typedef int	t_bool;
#endif
