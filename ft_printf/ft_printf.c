/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:54:30 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/21 23:28:34 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_format(va_list arg, const char *format, size_t *len)
{
	void	*ptr;

	if (*format == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (*format == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (*format == 'p')
	{
		ptr = va_arg(arg, void *);
		ft_putstr("0x", len);
		ft_putnbr_base_p((unsigned long)ptr, "0123456789abcdef", len);
	}
	else if (*format == 'u')
		ft_putunsigned(va_arg(arg, unsigned int), len);
	else if (*format == 'x')
		ft_putnbr_base_x(va_arg(arg, unsigned int), "0123456789abcdef", len);
	else if (*format == 'X')
		ft_putnbr_base_x(va_arg(arg, unsigned int), "0123456789ABCDEF", len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	len;

	va_start(arg, format);
	len = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			ft_handle_format(arg, format, &len);
			if (*format == '%')
				ft_putchar('%', &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(arg);
	return ((int)len);
}
