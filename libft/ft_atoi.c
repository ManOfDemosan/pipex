/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:29:15 by jaehwkim          #+#    #+#             */
/*   Updated: 2021/12/07 17:41:54 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long long	digit;
	int					button;

	digit = 0;
	button = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			button = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		digit *= 10;
		digit += (*str - '0');
		str++;
	}
	if (digit > 9223372036854775807 && button == 1)
		return (-1);
	else if (digit > 9223372036854775808ULL && button == -1)
		return (0);
	return ((int)digit * button);
}
