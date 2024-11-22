/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:28:05 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/22 15:46:58 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int a);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putu(unsigned int n);
int	ft_putint(int n, char spec);
int	ft_puthex(int n, char spec);

#endif




