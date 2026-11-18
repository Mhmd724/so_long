/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:44:52 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:44:54 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_char(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

size_t	count_strings(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && check_char(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !check_char(s[i], c))
			i++;
	}
	return (count);
}

size_t	count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && !check_char(s[i], c))
		i++;
	return (i);
}

char	*ft_word(char const *s, char c)
{
	size_t	len_word;
	size_t	i;
	char	*word;

	len_word = count_words(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**arr;
	size_t	i;

	if (!s)
		return (NULL);
	nb_words = count_strings(s, c) + 1;
	arr = (char **)malloc(sizeof(char *) * nb_words);
	if (!arr)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s && check_char(*s, c))
			s++;
		if (*s != '\0')
		{
			arr[i] = ft_word(s, c);
			i++;
		}
		while (*s && !check_char(*s, c))
			s++;
	}
	arr[i] = 0;
	return (arr);
}
