/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:14:30 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/04/25 16:18:45 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			child(fd, argv, envp);
		else if (pid > 0)
			parent(fd, argv, envp);
	}
	else
		arg_error();
	return (0);
}
