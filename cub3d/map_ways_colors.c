/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ways_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:52:53 by pskip             #+#    #+#             */
/*   Updated: 2022/07/31 22:06:03 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*mall_zone(char *zone, char *for_save)
{
	int	i;

	if (zone)
		error("more_then_one_way_to_same_side_of_the_wall\n");
	zone = (char *) malloc(sizeof(char) * (len_file_way(for_save) + 1));
	if (!zone)
		error("malloc_dir_or_collor\n");
	i = 0;
	while (for_save[i])
	{
		if (for_save[i] == '\n' || for_save[i] == ' '
			|| for_save[i] == '\t')
			zone[i] = '\0';
		else
			zone[i] = for_save[i];
		i++;
	}
	zone[i] = '\0';
	return (zone);
}

static void	switch_type(char **s_row, t_global *global)
{
	if (!ft_strncmp(s_row[0], "NO", 3))
		global->north = mall_zone(global->north, s_row[1]);
	else if (!ft_strncmp(s_row[0], "SO", 3))
		global->south = mall_zone(global->south, s_row[1]);
	else if (!ft_strncmp(s_row[0], "WE", 3))
		global->west = mall_zone(global->west, s_row[1]);
	else if (!ft_strncmp(s_row[0], "EA", 3))
		global->east = mall_zone(global->east, s_row[1]);
	else if (!ft_strncmp(s_row[0], "F", 2))
		global->floor = mall_zone(global->floor, s_row[1]);
	else if (!ft_strncmp(s_row[0], "C", 2))
		global->ceilling = mall_zone(global->ceilling, s_row[1]);
	else
		error("incorrect_data\n");
}

static int	is_map(char *row)
{
	char	*maps_char;
	int		i;

	maps_char = "012 ";
	i = -1;
	while (++i < 4)
	{
		if (maps_char[i] == row[0])
			return (1);
	}
	return (0);
}

static void	data_check(t_global *global)
{
	if (!global->ceilling || !global->east
		|| !global->floor || !global->north
		|| !global->south || !global->west)
		error("cant_find_texturs\n");
}

char	*add_info(int fd, t_global *global)
{
	char	*row;
	char	**splitted_row;

	row = get_next_line(fd);
	while (row)
	{
		splitted_row = ft_split(row, ' ');
		if (!splitted_row)
			exit(1);
		if (is_map(splitted_row[0]))
		{
			data_check(global);
			cleaner(splitted_row);
			break ;
		}
		global->line_start++;
		if (splitted_row[0][0] != '\n')
			switch_type(splitted_row, global);
		cleaner(splitted_row);
		free(row);
		row = get_next_line(fd);
	}
	if (!row)
		error("cant_find_map\n");
	return (row);
}
