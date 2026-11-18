/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:05:45 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 09:16:54 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char c)
{
	const char	*base;
	int			i;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	if (n > (ft_strlen(base) - 1))
		i += ft_puthexa(n / ft_strlen(base), c);
	i += ft_putchar(base[n % ft_strlen(base)]);
	return (i);
}
