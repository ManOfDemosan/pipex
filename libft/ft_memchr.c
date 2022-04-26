/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:31:02 by jaehwkim          #+#    #+#             */
/*   Updated: 2021/11/22 12:27:58 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*new_b;
	unsigned char	find;

	new_b = (unsigned char *)s;
	find = c;
	while (len--)
	{
		if (*new_b++ == find)
			return ((void *)(new_b - 1));
	}
	return (0);
}
