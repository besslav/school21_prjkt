/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:00:17 by pskip             #+#    #+#             */
/*   Updated: 2021/11/12 19:03:04 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int BUFFER_SIZE = 42;

char	*line_with_extra(char *line, int fd)
{
	char	*baff;
	int		byte_read;

	baff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!baff)
		return (NULL);
	byte_read = -1;
	while (!ft_strchr(line, '\n') && byte_read != 0)
	{
		byte_read = read(fd, baff, BUFFER_SIZE);
		printf("start: %s\n", baff);
		if (byte_read == -1)
		{
			free(baff);
			return (NULL);
		}
		baff[byte_read] = '\0';
		line = ft_strjoin(line, baff);
	}
	free(baff);
	return (line);
}

char	*get_real_line(char *line)
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
	real_line = ft_substr(line, 0, l);
	return (real_line);
}

char	*cut_last_line(char *line)
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
	new_line = ft_substr(line, n_place + 1, ft_strlen(line) - n_place - 1);
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*real_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = line_with_extra(line, fd);
	if (!line)
		return (NULL);
	real_line = get_real_line(line);
	line = cut_last_line(line);
	return (real_line);
}

int main()
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd2);
		//printf("f1 i=%d (%s)", i, line);
		free(line);

		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
