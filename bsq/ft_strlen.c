/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:49:51 by ymaragre          #+#    #+#             */
/*   Updated: 2021/07/27 14:49:55 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infa_map.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

int	**become_bi(t_inf *s_map)
{
	int	*str;
	int	**map_bi;
	int	i;
	int	j;

	str = (int *) malloc((s_map->count_str * (s_map->len_str + 1))
			* sizeof(int));
	map_bi = (int **) malloc((s_map->count_str + 1) * sizeof(int));
	i = 0;
	while (s_map->map[i])
	{
		j = 0;
		map_bi[i] = str + (s_map->len_str + 1) * i;
		while (s_map->map[i][j])
		{
			if (s_map->map[i][j] == s_map->empty)
				map_bi[i][j++] = 1;
			else
				map_bi[i][j++] = 0;
		}
		map_bi[i++][j] = '\0';
	}
	map_bi[i] = 0;
	return (map_bi);
}

t_inf	*check_inf(char	**map)
{
	t_inf	*inf;
	int		size;

	inf = (t_inf *) malloc(sizeof(t_inf));
	if (inf == 0)
		return (0);
	size = ft_strlen(map[0]);
	inf->full = map[0][size - 1];
	inf->obstacle = map[0][size - 2];
	inf->empty = map[0][size - 3];
	inf->map = map + 1;
	map[0][size - 3] = '\0';
	inf->count_str = ft_atoi(map[0]);
	inf->len_str = ft_strlen(map[1]);
	inf->map_bi = become_bi(inf);
	return (inf);
}
