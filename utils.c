/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:48:20 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/04/26 17:13:45 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	perror("\033[32mError");
	exit(EXIT_FAILURE);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char	*check_access(char *cmd, char **envp)
{
	int		i;
	char	*real_cmd;
	char	*slash_path;
	char	**paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i] != 0)
	{
		slash_path = ft_strjoin(paths[i], "/");
		real_cmd = ft_strjoin(slash_path, cmd);
		if (access(real_cmd, X_OK) == 0)
		{
			free_paths(paths);
			return (real_cmd);
		}
		free(slash_path);
		free(real_cmd);
		i++;
	}
}

void	make_stream(char *cmd, char **envp)
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
