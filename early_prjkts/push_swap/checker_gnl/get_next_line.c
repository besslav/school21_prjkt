/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:00:17 by pskip             #+#    #+#             */
/*   Updated: 2022/01/21 17:04:40 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*line_with_extra(char *line, int fd)
{
	char	*baff;
	int		byte_read;

	baff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!baff)
		exit(1);
	byte_read = -1;
	while (!ft_strchr(line, '\n') && byte_read != 0)
	{
		byte_read = read(fd, baff, BUFFER_SIZE);
		if (byte_read == -1)
			exit(1);
		baff[byte_read] = '\0';
		line = ft_strjoin(line, baff);
	}
	free(baff);
	return (line);
}

static char	*get_real_line(char *line)
{
	char	*real_line;
	int		l;

	l = 0;
	if (!line[0])
		return (NULL);
	while (line[l] != '\n' && line[l])
		l++;
	if (line[l] == '\n')
		l++;
	real_line = ft_substr_gnl(line, 0, l);
	return (real_line);
}

static char	*cut_last_line(char *line)
{
	char	*new_line;
	int		n_place;

	n_place = 0;
	while (line[n_place] != '\n' && line[n_place])
		n_place++;
	if (!line[n_place])
	{
		free(line);
		return (NULL);
	}
	new_line = ft_substr_gnl(line, n_place + 1, ft_strlen(line) - n_place - 1);
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*real_line;

	line = line_with_extra(line, fd);
	if (!line[0])
		return (NULL);
	real_line = get_real_line(line);
	line = cut_last_line(line);
	return (real_line);
}
