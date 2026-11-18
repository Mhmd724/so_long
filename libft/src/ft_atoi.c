/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:38:21 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 09:04:20 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_space(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	check_sign(char c, int *sign)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long long int	num;
	int				sign;

	num = 0;
	sign = 1;
	while (*nptr && check_space(*nptr))
		nptr++;
	if (check_sign(*nptr, &sign))
		nptr++;
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}
