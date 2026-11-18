/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:46:55 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:46:57 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t size)
{
	size_t	i;
	size_t	j;

	if (!str && !size)
		return (NULL);
	if (!*substr)
		return ((char *)str);
	i = 0;
	while (str[i] && i < size)
	{
		j = 0;
		while (str[i + j] == substr[j]
			&& substr[j] && i + j < size)
		{
			if (!substr[j + 1])
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
