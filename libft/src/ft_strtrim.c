/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:47:32 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:47:33 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*create_alloc(size_t s1_size)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (s1_size + 1));
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_size;
	size_t	i;
	size_t	k;
	char	*p;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && check_set(s1[i], set))
		i++;
	s1_size = ft_strlen(s1);
	j = s1_size;
	while (j > i && check_set(s1[j - 1], set))
		j--;
	p = create_alloc(j - i);
	if (!p)
		return (NULL);
	k = 0;
	while (i < j)
		p[k++] = s1[i++];
	p[k] = '\0';
	return (p);
}
