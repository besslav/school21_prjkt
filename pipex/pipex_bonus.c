/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:46:32 by pskip             #+#    #+#             */
/*   Updated: 2022/01/27 17:03:58 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char *av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		errors("can`t create channel");
	pid = fork();
	if (pid == -1)
		errors("cant clone process");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(av, env);
	}
	else
	{	
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

static void	here_doc_child(int *fd, char *limiter)
{
	char	*line;

	close(fd[0]);
	while (get_next_line(&line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
	}
	exit(EXIT_SUCCESS);
}

static void	here_doc(int ac, char *limiter)
{
	int		fd[2];
	pid_t	pid;

	if (ac < 6)
		errors("bad input for here_doc");
	if (pipe(fd) == -1)
		errors("can`t create channel");
	pid = fork();
	if (pid == -1)
		errors("cant clone process");
	if (!pid)
		here_doc_child(fd, limiter);
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		file_in;
	int		file_out;

	if (ac < 5)
		errors("wrong input");
	i = 2;
	if (!(ft_strncmp("here_doc", av[1], 8)))
	{
		file_out = opener(av[ac - 1], 0);
		here_doc(ac, av[2]);
		i++;
	}
	else
	{
		file_in = opener(av[1], 1);
		file_out = opener(av[ac - 1], 2);
		dup2(file_in, STDIN_FILENO);
	}
	while (i < ac - 2)
		child_process(av[i++], env);
	dup2(file_out, STDOUT_FILENO);
	execute(av[i], env);
}
