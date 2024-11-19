/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:41:08 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/19 17:56:57 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	arg;

	va_start(arg, str);
	len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'c' || *(str + 1) == 's')
			len += ft_putchar(va_arg(arg, char *));
		/*else if (*str == '%' && *(str + 1) == 'p')
			len += ft_putchar(va_arg(arg, int));
		else if (*str == '%' && *(str + 1) == 'd')
			len += ft_putchar(va_arg(arg, int));
		else if (*str == '%' && *(str + 1) == 'i')
			len += ft_putchar(va_arg(arg, int));
		else if (*str == '%' && *(str + 1) == 'x')
			len += ft_putchar(va_arg(arg, int));
		else if (*str == '%' && *(str + 1) == 'x')
			len += ft_putchar(va_arg(arg, int));
		else
			len += ft_putchar(*str);*/
		str++;
	}
	va_end(arg);
	return (len);
}
