/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:45:14 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:45:16 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	char	*temp;
	size_t	length;

	length = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (length + 1));
	if (!p)
		return (NULL);
	temp = p;
	while (*s)
		*temp++ = *s++;
	*temp = '\0';
	return (p);
}
