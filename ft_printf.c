/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:41:08 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/21 12:53:00 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_check_spec(const char *format, const char *spec)
{
    if (*format++ != '%')
        return (0);
    while (*spec)
        if (*format == *spec++)
            return (1);
    return (0);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		arg;

	va_start(arg, format);
	len = 0;
	while (*format)
	{
		if (ft_check_spec(format, "s") && *format++) // %s
			len += ft_putstr(va_arg(arg, char *));
		else if (ft_check_spec(format, "id") && *format++) // %d + %i + %x + %X + %c
			len += ft_putchar(va_arg(arg, int));
		else if (ft_check_spec(format, "p") && *format++) // %p
			len += ft_putptr(va_arg(arg, void *));
		else if (ft_check_spec(format, "xX") && *format++) // %x + %X
			len += ft_putchar(va_arg(arg, int));
		else if (ft_check_spec(format, "%") && *format++) // %%
			len += ft_putchar('%');
		else if (ft_check_spec(format, "u") && *format++) // %u
			len += ft_putu(va_arg(arg, unsigned int));
		else if (*format == '%') // Wrong Specifier
			return (va_end(arg), -1);
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (len);
}
