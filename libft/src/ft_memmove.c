/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:43:35 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:43:36 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	p = (unsigned char *)dest;
	if (dest > src)
		while (n--)
			p[n] = ((unsigned char *)src)[n];
	else
		while (n--)
			*p++ = *(unsigned char *)src++;
	return (dest);
}
