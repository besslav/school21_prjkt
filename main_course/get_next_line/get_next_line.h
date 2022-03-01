/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:43:49 by pskip             #+#    #+#             */
/*   Updated: 2021/10/21 18:13:47 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int findit);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif