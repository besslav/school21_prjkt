/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 23:26:40 by pskip             #+#    #+#             */
/*   Updated: 2021/08/03 23:26:43 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

void	ft_putstr(char *str, int i);
int		ft_atoi(char *str);

int	display_error(char *file, char *pros)
{
	if (errno)
	{
		ft_putstr(basename(pros), 2);
		write(2, ": ", 2);
		ft_putstr(file, 2);
		write(2, ": ", 2);
		ft_putstr(strerror(errno), 2);
		write(2, "\n", 1);
		return (0);
	}
	return (1);
}

void	exept(int argc)
{
	char	c;

	if (argc == 1)
	{
		while (1)
		{
			read(0, &c, 1);
		}
	}
}

void	reader(char *buf, char **argv, int i, int fd)
{
	int	rd;
	int	circle;
	int	rd2;

	circle = 0;
	rd = ft_atoi(argv[2]);
	while (rd == ft_atoi(argv[2]))
	{
		rd = read(fd, buf, ft_atoi(argv[2]));
		if (!display_error(argv[i], argv[0]))
			return ;
		circle++;
	}
	close(fd);
	fd = open(argv[i], O_RDONLY);
	if (!display_error(argv[i], argv[0]))
		return ;
	rd2 = read(fd, buf, rd);
	while (--circle > 0)
	{
		rd2 = read(fd, buf, ft_atoi(argv[2]));
	}
	buf[rd2] = '\0';
	ft_putstr(buf, 1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*buf;
	int		i;

	buf = (char *) malloc(ft_atoi(argv[2]) + 1);
	i = 2;
	exept(argc);
	while (++i < argc)
	{
		errno = 0;
		fd = open(argv[i], O_RDONLY);
		if (!display_error(argv[i], argv[0]))
			continue ;
		if (argc > 4)
		{
			write(1, "==> ", 4);
			ft_putstr(basename(argv[i]), 1);
			write(1, " <==\n", 5);
		}
		if (argv[2][0] != '0')
			reader(buf, argv, i, fd);
		if (i < argc - 1)
			write(1, "\n", 1);
		close(fd);
	}
	return (0);
}
