/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:43:43 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/22 14:29:12 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putu(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
