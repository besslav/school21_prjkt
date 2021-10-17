/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 22:39:32 by ymaragre          #+#    #+#             */
/*   Updated: 2021/08/03 07:05:29 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "infa_map.h"

char	*ft_mapcreator(char *fn);
char	**ft_split(char *str);
int		ft_map_error(char **map);
void	n_to_0(char *str);
t_inf	*check_inf(char	**str);
char	*read_to_file(void);
void	main_alg(t_inf *data);
void	free_all(t_inf *s_map, char **map, char *mapstr);

int	main(int argc, char **argv)
{
	int		i;
	char	*mapstr;
	char	**map;
	t_inf	*s_map;

	i = 1;
	if (argc == 1)
	{
		argc++;
		argv[1] = read_to_file();
	}
	while (i < argc)
	{
		mapstr = ft_mapcreator(argv[i++]);
		map = ft_split(mapstr);
		n_to_0(mapstr);
		if (ft_map_error(map))
			continue ;
		s_map = check_inf(map);
		main_alg(s_map);
		free_all(s_map, map, mapstr);
		if (i != argc)
			write(1, "\n", 1);
	}
	return (0);
}

char	*read_to_file(void)
{
	char	c;
	char	*name;
	int		of;
	int		rf;

	rf = 1;
	name = "map_zero";
	of = open(name, O_WRONLY | O_TRUNC, S_IWRITE | S_IREAD);
	while (rf > 0)
	{
		rf = read(0, &c, 1);
		write(of, &c, 1);
	}
	close (of);
	return (name);
}

void	free_all(t_inf *s_map, char **map, char *mapstr)
{
	free(map);
	free(mapstr);
	free(s_map);
}
