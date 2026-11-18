/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:07:00 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 09:07:02 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int num);
int		ft_putaddress(void *format);
int		ft_putstr(const char *str);
int		ft_puthexa(unsigned long n, char format);
int		ft_putunsigned(unsigned long n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
#endif
