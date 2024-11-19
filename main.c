/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:04 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/19 17:57:08 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *, ...);

int	main(void)
{
	printf("+++++++++++++++++++++++++++++START_CHAR_TEST+++++++++++++++++++++++++++++\n");
	char a = 'a';


	int len_sys = printf("%c");
	int len_my = ft_printf("%c", a);

	printf("\n");
	printf("_____________________________LEN_CHAR_TEST_______________________________\n");
	printf("sys: %d\n", len_sys);
	printf("my: %d\n", len_my);
	printf("-----------------------------END_CHAR_TEST-----------------------------\n");

	return (0);
}
