/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:40:22 by jmiranda          #+#    #+#             */
/*   Updated: 2023/07/12 13:27:42 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(size_t n, size_t base, char *hex_type, size_t *i)
{
	if (n >= base)
		ft_putptr(n / base, base, hex_type, i);
	*i += write(1, hex_type + (n % base), 1);
}

static void	ft_putnbr(ssize_t n, int base, char *hex_type, size_t *i)
{
	if (n < 0)
	{
		*i += write(1, "-", 1);
		n *= -1;
	}
	if (n >= base)
		ft_putnbr(n / base, base, hex_type, i);
	*i += write(1, hex_type + (n % base), 1);
}

static void	ft_putstr(char	*str, size_t *i)
{
	if (!str)
		*i += write(1, "(null)", 6);
	else
		while (*str != '\0')
			*i += write(1, str++, 1);
}

static void	ft_flags(char *fmt, va_list ap, size_t *i, char c)
{
	if (*fmt == 'c')
	{
		c = va_arg(ap, int);
		*i += write(1, &c, 1);
	}
	if (*fmt == 's')
		ft_putstr((char *)va_arg(ap, char *), i);
	if (*fmt == '%')
		*i += write(1, "%", 1);
	if (*fmt == 'p')
	{
		*i += write(1, "0x", 2);
		ft_putptr((size_t)va_arg(ap, size_t), 16, HEX_LO, i);
	}
	if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr((ssize_t)va_arg(ap, int), 10, HEX_LO, i);
	if (*fmt == 'u')
		ft_putnbr((size_t)va_arg(ap, unsigned int), 10, HEX_LO, i);
	if (*fmt == 'x')
		ft_putnbr((size_t)va_arg(ap, unsigned int), 16, HEX_LO, i);
	if (*fmt == 'X')
		ft_putnbr((size_t)va_arg(ap, unsigned int), 16, HEX_HI, i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	i;

	i = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%' && fmt++)
		{
			ft_flags((char *)fmt, ap, &i, '\0');
			fmt++;
		}
		else
			i += write(1, fmt++, 1);
	}
	va_end(ap);
	return (i);
}
