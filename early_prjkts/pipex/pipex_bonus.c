/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:46:32 by pskip             #+#    #+#             */
/*   Updated: 2022/01/26 15:02:21 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int i, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if(pipe(fd) == -1)
		errors("can`t create channel");
	pid = fork();
	if (pid == -1)
		errors("cant clone process");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(av[i], env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	parent_process(int ac, char **av, char **env)
{
	int file_fd;

	file_fd = open(av[ac - 1], O_WRONLY | O_CREAT, 00777);
	if (file_fd == -1)
		errors("cant open file");
	dup2(file_fd, STDOUT_FILENO);
	execute(av[3], env);
	//close(file_fd);
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int file_fd;

	if (ac < 5)
		errors("wrong input");
	i = 2;
	file_fd = open(av[1], O_RDONLY);
	if (file_fd == -1)
		errors("cant open file");
	dup2(file_fd, STDIN_FILENO);
	while (i < ac - 2)
		child_process(i++, av, env);
	parent_process(ac, av, env);
}
