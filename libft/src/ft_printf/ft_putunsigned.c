/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:06:11 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 09:08:12 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned long n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	if (n > (ft_strlen(base) - 1))
		i += ft_putunsigned(n / ft_strlen(base));
	i += ft_putchar(base[n % ft_strlen(base)]);
	return (i);
}
