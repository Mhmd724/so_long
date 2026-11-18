/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:05:54 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 09:05:55 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_nbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	nbr_length;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	nbr_length = count_nbr(n);
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (nbr_length);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	return (nbr_length);
}
