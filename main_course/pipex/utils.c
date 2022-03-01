/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:21:43 by pskip             #+#    #+#             */
/*   Updated: 2022/01/27 17:01:41 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	errors(char *str)
{
	perror(str);
	exit(1);
}

int	opener(char *file_name, int way)
{
	int	fd;

	if (way == 0)
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (way == 1)
		fd = open(file_name, O_RDONLY);
	else
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		errors("cant open file");
	return (fd);
}

void	execute(char *command, char **env)
{
	char	**coma_flags;
	int		i;
	char	**all_paths;
	char	*this_way;

	coma_flags = ft_split(command, ' ');
	i = 0;
	while (ft_strncmp("PATH", env[i], 4))
		i++;
	all_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		this_way = ft_strjoin(all_paths[i++], "/");
		this_way = ft_strjoin(this_way, coma_flags[0]);
		if (!(access(this_way, 0)))
		{
			if (execve(this_way, coma_flags, env) == -1)
				errors("cant execute");
		}
		free(this_way);
	}
	errors("cant find command");
}
