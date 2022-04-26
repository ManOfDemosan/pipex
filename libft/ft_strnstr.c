/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:08:02 by jaehwkim          #+#    #+#             */
/*   Updated: 2021/12/07 17:08:41 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == 0)
		return ((char *)haystack);
	while (*haystack != 0 && len-- > 0)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i) && i < len + 1)
		{
			i++;
			if (*(needle + i) == 0)
				return ((char *) haystack);
		}
		haystack++;
	}
	return (0);
}
