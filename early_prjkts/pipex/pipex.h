/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:24:12 by pskip             #+#    #+#             */
/*   Updated: 2022/01/25 16:45:06 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int		errors(char *str);
void	execute(char *command, char **env);

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *first, const char *second, int end);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, int start, int len);
int		ft_strlen(const char *string);

#endif