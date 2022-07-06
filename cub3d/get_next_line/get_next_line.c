/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:44:08 by pskip             #+#    #+#             */
/*   Updated: 2022/06/22 17:44:10 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static
int	invalid_args(int fd)
{
	if (read(fd, (void *)0, 0) < 0 || BUFFER_SIZE <= 0)
		return (1);
	return (0);
}

static
int	cant_read(int fd, char **leftovers)
{
	long	count_read;

	if (!*leftovers)
	{
		*leftovers = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!*leftovers)
			return (1);
		count_read = read(fd, *leftovers, BUFFER_SIZE);
		if (count_read > 0)
		{
			(*leftovers)[count_read] = '\0';
			return (0);
		}
		free(*leftovers);
		*leftovers = (void *)0;
	}
	if (!*leftovers)
		return (1);
	return (0);
}

static
void	cut_leftovers(char **leftovers, long j)
{
	char	*new_leftovers;

	if ((*leftovers)[j] && (*leftovers)[j + 1])
		new_leftovers = ft_strdup2(&(*leftovers)[j + 1]);
	else
		new_leftovers = (void *)0;
	free(*leftovers);
	*leftovers = new_leftovers;
}

static
int	add_piece_of_line(char **line, char **leftovers, long *len)
{
	char	*piece;
	char	*new_line;
	long	j;

	j = 0;
	while ((*leftovers)[j] && (*leftovers)[j] != '\n')
		j++;
	new_line = (void *)0;
	piece = ft_substr2(*leftovers, 0, j + ((*leftovers)[j] != '\0'));
	if (*line && piece)
	{
		new_line = ft_strjoin2(*line, piece);
		free(piece);
	}
	else if (!*line && piece)
		new_line = piece;
	if (*line)
		free(*line);
	*line = new_line;
	*len += j + ((*leftovers)[j] == '\n');
	cut_leftovers(leftovers, j);
	if (!*line || (*line)[*len - 1] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	long		len;
	char		*line;
	static char	*arr[1024];

	if (invalid_args(fd))
		return ((void *)0);
	line = (void *)0;
	len = 0;
	while (!cant_read(fd, &arr[fd]))
		if (add_piece_of_line(&line, &arr[fd], &len))
			break ;
	return (line);
}
