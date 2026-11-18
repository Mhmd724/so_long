/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:05:24 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/22 18:06:44 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rec_print(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n > (ft_strlen(base) - 1))
		len += rec_print(n / ft_strlen(base), base);
	len += ft_putchar(base[n % ft_strlen(base)]);
	return (len);
}

int	ft_putaddress(void *format)
{
	unsigned long	n;
	char			*base;
	int				len;

	base = "0123456789abcdef";
	n = (unsigned long)format;
	len = ft_putstr("0x");
	len += rec_print(n, base);
	return (len);
}
