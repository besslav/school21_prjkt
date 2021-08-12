/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 02:00:10 by pskip             #+#    #+#             */
/*   Updated: 2021/08/03 02:00:13 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str);

int	errorcheck(int argc)
{
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	return (1);
}

int	errorread(int base)
{
	if (base < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		ret;
	int		fd;
	char	buf[11];

	if (errorcheck(argc))
	{
		fd = open(argv[1], O_RDONLY);
		if (!errorread(fd))
			return (0);
		ret = -1;
		while (ret)
		{
			ret = read(fd, buf, 10);
			if (!errorread(ret))
				return (0);
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		close(fd);
	}
	return (0);
}
