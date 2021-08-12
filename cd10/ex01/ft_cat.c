/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 08:09:10 by pskip             #+#    #+#             */
/*   Updated: 2021/08/03 08:09:13 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *str, int i);

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
			write(1, &c, 1);
		}
	}
}

int	main(int argc, char **argv)
{
	int		rd;
	int		fd;
	char	buf[11];
	int		i;

	i = 0;
	exept(argc);
	while (++i < argc)
	{
		errno = 0;
		fd = open(argv[i], O_RDONLY);
		if (!display_error(argv[i], argv[0]))
			continue ;
		rd = -1;
		while (rd)
		{
			rd = read(fd, buf, 10);
			if (!display_error(argv[i], argv[0]))
				break ;
			buf[rd] = '\0';
			ft_putstr(buf, 1);
		}
		close(fd);
	}
	return (0);
}
