/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:41:08 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/20 17:26:12 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list		arg;

	va_start(arg, format);
	len = 0;
	while (*format)
	{
		if (ft_strnstr(format, "%c", 2) && *format++) // %c
			len += ft_putchar(va_arg(arg, int));
		else if (ft_strnstr(format, "%s", 2) && *format++) // %s
			len += ft_putstr(va_arg(arg, char *));
		else if (ft_strnstr(format, "%d", 2) || ft_strnstr(format, "%i", 2) && *format++)
			len += ft_putchar(va_arg(arg, int));
		else if (ft_strnstr(format, "%p", 2) && *format++) // %p
			len += ft_putptr(va_arg(arg, void *));
		/*else if (*format == '%' && *(format + 1) == 'x' || *(format + 1) == 'x' && *format++)
			len += ft_putchar(va_arg(arg, int));*/
		else if (ft_strnstr(format, "%%", 2) && *format++)
			len += ft_putchar('%');
		else if (*format == '%')
			return (va_end(arg), -1);
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (len);
}
