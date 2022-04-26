/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:48:20 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/04/26 13:55:02 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	perror("\033[32mError");
	exit(EXIT_FAILURE);
}

void	make_stream(char *av, char **envp)
{
	char	**argv;
	char	*real_av;

	argv = ft_split(av, ' ');
	real_av = check_access(argv[0], envp);
	if(real_av == 0)
		error_exit();
	execve(real_av, argv, envp);	
}

int	arg_error(void)
{
	printf("\033[32mError: Bad arguments");
	return (1);
}
