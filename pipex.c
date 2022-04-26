/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:14:30 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/04/26 13:48:02 by jaehwkim         ###   ########.fr       */
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
	if (dup2(infile, STDOUT_FILENO) == -1)
		error_exit();
	close(fd[0]);
	make_stream(argv[2], envp);
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
