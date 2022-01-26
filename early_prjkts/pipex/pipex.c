/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:59:03 by pskip             #+#    #+#             */
/*   Updated: 2022/01/25 22:11:43 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **av, char **env)
{
	int file_fd;

	file_fd = open(av[1], O_RDONLY);
	if (file_fd == -1)
		errors("cant open file");
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_fd, STDIN_FILENO);
	execute(av[2], env);
	close(file_fd);
}

void	parent_process(int *fd, char **av, char **env)
{
	int file_fd;

	file_fd = open(av[4], O_WRONLY | O_CREAT, 00777);
	if (file_fd == -1)
		errors("cant open file");
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	execute(av[3], env);
	close(file_fd);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		errors("wrong input");
	if(pipe(fd) == -1)
		errors("can`t create channel");
	pid = fork();
	if (pid == -1)
		errors("cant clone process");
	if (!pid)
		child_process(fd, av, env);
	if (waitpid(pid, NULL, 0) == -1)
		errors("error with waiting child process");
	parent_process(fd, av, env);
}
