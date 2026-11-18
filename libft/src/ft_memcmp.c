/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:43:15 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:43:16 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *lhs, const void *rhs, size_t n)
{
	const unsigned char	*p;
	const unsigned char	*s;

	p = (const unsigned char *)lhs;
	s = (const unsigned char *)rhs;
	while (n > 0)
	{
		if (*p != *s)
			return (*p - *s);
		++p;
		++s;
		n--;
	}
	return (0);
}
