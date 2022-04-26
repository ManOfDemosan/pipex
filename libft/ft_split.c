/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:31:31 by jaehwkim          #+#    #+#             */
/*   Updated: 2021/12/08 00:58:50 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, char c)
{
	size_t	con;

	con = 0;
	while (*s)
	{
		if (*s != c)
		{
			con++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (con);
}

static char	**ft_free_ptr(char **s, int i)
{
	while (--i >= 0 && s[i])
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static char	**go_split(char const *s, char c, char **buf)
{
	char	*from;
	int		i;

	i = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				s++;
			buf[i++] = ft_substr(from, 0, (s - from));
			if (buf[i - 1] == 0)
				return (ft_free_ptr(buf, i));
		}
		else
			s++;
	}
	buf[i] = NULL;
	return (buf);
}

char	**ft_split(char const *s, char c)
{
	char	**buf;

	if (s == 0)
		return (NULL);
	buf = (char **)malloc((ft_len(s, c) + 1) * sizeof(char *));
	if (buf == 0)
		return (NULL);
	go_split(s, c, buf);
	return (buf);
}
