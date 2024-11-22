/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:42:56 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/22 14:36:41 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(int hex, char spec)
{
	if (spec == 'x')
	{
		if (hex >= 10)
			return (ft_putchar(hex - 10 + 'a'));
		else
			return (ft_putchar(hex + '0'));
	}
	if (spec == 'X')
	{
		if (hex >= 10)
			return (ft_putchar(hex - 10 + 'A'));
		else
			return (ft_putchar(hex + '0'));
	}
	return (0);
}

int	ft_puthex(int n, char spec)
{
	int	len;
	int	i;

	len = 0;
	i = (sizeof(n) << 3) - 4;
	while (((n >> i) & 0xf) == 0x0 && i >= 4)
		i -= 4;
	while (i >= 0)
	{
		len += ft_hex((n >> i) & 0xf, spec);
		i -= 4;
	}
	return (len);
}
