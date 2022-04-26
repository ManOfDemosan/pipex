/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:48:20 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/04/26 14:38:25 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	perror("\033[32mError");
	exit(EXIT_FAILURE);
}

char	*check_access(char *cmd, char **envp)
{
}

void	make_stream(char *cmd char **envp)
{
	char	**argv;
	char	*real_cmd;

	argv = ft_split(cmd, ' ');
	real_cmd = check_access(argv[0], envp);
	if (real_cmd == 0)
		error_exit();
	execve(real_cmd, argv, envp);
}

int	arg_error(void)
{
	printf("\033[32mError: Bad arguments");
	return (1);
}
