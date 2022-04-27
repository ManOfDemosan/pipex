/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:14:30 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/04/27 09:35:10 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pro(int *fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error_exit();
	if (dup2(infile, STDIN_FILENO) == -1)
		error_exit();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error_exit();
	close(fd[0]);
	make_stream(argv[2], envp);
}

void	parent_pro(int *fd, char **argv, char **envp)
{
	int	outfile;
	int	status;

	waitpid(-1, &status, WNOHANG);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error_exit();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_exit();
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_exit();
	close(fd[1]);
	make_stream(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_exit();
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
			child_pro(fd, argv, envp);
		else if (pid > 0)
			parent_pro(fd, argv, envp);
	}
	else
		arg_error();
	return (0);
}
