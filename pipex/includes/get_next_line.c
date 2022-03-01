/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:00:17 by pskip             #+#    #+#             */
/*   Updated: 2022/01/26 19:03:22 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
