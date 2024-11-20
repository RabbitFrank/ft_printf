/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:56 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/20 17:18:56 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char ft_puthex(int n)
{
	if (0 <= n && n <= 9)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

int	ft_putptr(void *ptr)
{
    int 		i;
    uintptr_t 	p;
	int			len;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	p = (uintptr_t)ptr;
    len += ft_putstr("0x");
	i = (sizeof(p) << 3) - 4;
	while (((p >> i) & 0xf) == 0x0)
		i -= 4;
    while (i>=0)
	{
		len += ft_putchar(ft_puthex((p >> i) & 0xf));
		i -= 4;
    }
	return (len);
}