/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:24:12 by pskip             #+#    #+#             */
/*   Updated: 2022/01/27 17:03:46 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define BUFFER_SIZE 40
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

int		errors(char *str);
void	execute(char *command, char **env);
int		opener(char *file_name, int way);

char	**ft_split(char const *s, char c);
int		ft_strncmp(char *first, char *second, int end);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, int start, int len);
int		ft_strlen(const char *string);
char	*ft_strchr(char *str, int findit);
int		get_next_line(char **line);

#endif