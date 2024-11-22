/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:41:08 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/22 14:28:36 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (ft_check_spec(format, "s") && *format++)			// %s
			len += ft_putstr(va_arg(arg, char *));
		else if (ft_check_spec(format, "idxXc") && *format++)	// %d + %i + %x + %X + %c
			len += ft_putint(va_arg(arg, int), *format);
		else if (ft_check_spec(format, "p") && *format++)		// %p
			len += ft_putptr(va_arg(arg, void *));
		else if (ft_check_spec(format, "%") && *format++)		// %%
			len += ft_putchar('%');
		else if (ft_check_spec(format, "u") && *format++)		// %u
			len += ft_putu(va_arg(arg, unsigned int));
		else if (*format == '%')								// Wrong Specifier
			return (va_end(arg), -1);
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (len);
}
