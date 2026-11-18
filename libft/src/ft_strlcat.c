/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:45:51 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:45:52 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	total_len;

	if ((!dest || !src) && !n)
		return (0);
	dest_len = 0;
	while (dest[dest_len] && dest_len < n)
		dest_len++;
	if (dest_len >= n)
		return (n + ft_strlen(src));
	else
		total_len = dest_len + ft_strlen(src);
	while (*src && (dest_len + 1) < n)
	{
		dest[dest_len] = *src++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (total_len);
}
