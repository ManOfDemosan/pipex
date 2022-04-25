/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:48:20 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/04/25 16:19:05 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	perror("\033[32mError");
	exit(EXIT_FAILURE);
}

int	arg_error(void)
{
	printf("\033[32mError: Bad arguments");
	return (1);
}
