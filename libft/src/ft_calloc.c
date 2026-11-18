/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:39:00 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:39:02 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 2147483647 / size)
		return (NULL);
	p = (void *)malloc(size * nmemb);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nmemb);
	return (p);
}
