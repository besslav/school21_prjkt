/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:08:11 by ymaragre          #+#    #+#             */
/*   Updated: 2021/08/10 19:08:13 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);
int	err_inf(char *str);
int	err_strlen(char **map);
int	err_fill(char **map);

int	ft_map_error(char **map)
{
	if (map == 0)
	{
		write(2, "Error map\n", 10);
		return (1);
	}
	if (err_inf(map[0]))
	{
		write(2, "Error map\n", 10);
		return (1);
	}
	if (err_strlen(map + 1))
	{
		write(2, "Error map\n", 10);
		return (1);
	}
	if (err_fill(map))
	{
		write(2, "Error map\n", 10);
		return (1);
	}
	return (0);
}

int	err_inf(char *str)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	if (size < 4 && (str[0] < '0' && str[0] > '9'))
		return (1);
	i = 0;
	while (i < size - 3)
	{
		if (str[i] < '0' && str[i] > '9')
			return (1);
		i++;
	}
	while (i < size)
	{
		if (str[i] < 32 && str[i] > 126)
			return (1);
		i++;
	}
	if (str[size - 1] == str[size - 2]
		|| str[size - 1] == str[size - 3]
		|| str[size - 2] == str[size - 3])
		return (1);
	return (0);
}

int	err_strlen(char **map)
{
	int	i;

	i = 0;
	if (ft_strlen(map[i]) == 0)
		return (0);
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	err_fill(char **map)
{
	char	c[3];
	int		size;
	int		i;
	int		j;

	size = ft_strlen(map[0]);
	c[0] = map[0][size - 1];
	c[1] = map[0][size - 2];
	c[2] = map[0][size - 3];
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != c[0] && map[i][j] != c[1] && map[i][j] != c[2])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
