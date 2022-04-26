/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:52:53 by jaehwkim          #+#    #+#             */
/*   Updated: 2021/12/02 14:38:48 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	if (len == 0)
		return (ft_strlen (src));
	i = 0;
	while (*src != 0 && i + 1 < len)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = 0;
	while (*src != 0)
	{
		src++;
		i++;
	}
	return (i);
}
