/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:07:50 by ymaragre          #+#    #+#             */
/*   Updated: 2021/08/10 19:08:01 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	size_finder(char *fn)
{
	int		size;
	int		fd;
	char	buf[31];
	int		rd;

	size = 0;
	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	rd = -1;
	while (rd)
	{
		rd = read(fd, buf, 30);
		buf[rd] = '\0';
		size += rd;
	}
	close(fd);
	return (size);
}

void	arr_creator(char *fn, char *arr)
{
	int		fd;
	char	buf[31];
	int		rd;
	int		i;
	int		j;

	i = 0;
	fd = open(fn, O_RDONLY);
	rd = -1;
	while (rd)
	{
		rd = read(fd, buf, 30);
		buf[rd] = '\0';
		j = 0;
		while (buf[j])
		{
			arr[i] = buf[j];
			j++;
			i++;
		}
	}
	close(fd);
}

char	*ft_mapcreator(char *fn)
{
	char	*arrline;
	int		i;
	int		size;
	char	putit;

	i = 0;
	size = size_finder(fn);
	if (size == 0)
		return (0);
	arrline = (char *) malloc(sizeof(char) * (size + 1));
	if (arrline == 0)
		return (0);
	arr_creator(fn, arrline);
	while (arrline[i])
	{
		putit = arrline[i];
		i++;
	}
	return (arrline);
}
