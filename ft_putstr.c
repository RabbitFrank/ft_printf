/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:38:59 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/20 16:55:01 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (*str)
	{
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}
