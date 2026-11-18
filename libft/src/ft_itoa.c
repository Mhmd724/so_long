/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:40:44 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 08:40:46 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rev_nb(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

int	count_num(int n, int *sign)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		*sign = -1;
		count++;
	}
	else
		*sign = 1;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}

char	*mem_alloc(int count)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * count);
	if (!p)
		return (NULL);
	return (p);
}

char	*check_nb(int n)
{
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (ft_strdup("0"));
}

char	*ft_itoa(int n)
{
	int		count;
	char	*p;
	int		sign;
	int		i;

	if (n == 2147483647 || n == -2147483648 || n == 0)
		return (check_nb(n));
	count = count_num(n, &sign);
	p = mem_alloc(count);
	if (!p)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		p[i++] = sign * (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		p[i++] = '-';
	p[i] = '\0';
	return (rev_nb(p));
}
