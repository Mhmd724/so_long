/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:43:26 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:43:28 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;

	if (!dest && !src)
		return (dest);
	p = (unsigned char *)dest;
	while (n > 0)
	{
		*p++ = *(unsigned char *)src++;
		n--;
	}
	return (dest);
}
