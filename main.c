/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:04 by mlitvino          #+#    #+#             */
/*   Updated: 2024/11/21 12:56:55 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int len_sys, len_my;

	printf("_____________________________START_CHAR_TEST____________________________\n\n");

	int ch_loop = 0;
	int i = -50;

	for (; i < 200 && ch_loop == 1; i++){ // Loop Test
		printf("sys: ");
		len_sys = printf("%c", i);
		printf(" | my: ");
		fflush(stdout);
		len_my = ft_printf("%c", i);
		printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);
		printf("%d\n", i);
		printf("________________\n");
	}
	if (ch_loop == 0) // Normal Test
	{
		char a = 'a';

		printf("sys: ");
		len_sys = printf("%c", a);
		printf(" | my: ");
		fflush(stdout);
		len_my = ft_printf("%c", a);
		printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);
	}

	printf("\n-----------------------------END_CHAR_TEST-----------------------------\n");



	printf("_____________________________START_STR_TEST____________________________\n\n");

	char *pos_str = "HELLO"; // Positive Test


	printf("sys: ");
	len_sys = printf("%s", pos_str);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%s", pos_str);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *null_str = NULL; // Null Test

	printf("sys: ");
	len_sys = printf("%s", null_str);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%s", null_str);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *garb_str; // Garbage Test

	printf("sys: ");
	len_sys = printf("%s", garb_str);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%s", garb_str);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *emp_str = ""; // Empty Test

	printf("sys: ");
	len_sys = printf("%s", emp_str);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%s", emp_str);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);


	printf("\n-----------------------------END_STR_TEST-----------------------------\n");



	printf("_____________________________START_PTR_TEST____________________________\n\n");

	void *pos_p = (void *)0x7fffffdbf2; // Positive Test

	printf("sys: ");
	len_sys = printf("%p", pos_p);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%p", pos_p);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	void *z_p = (void *)0x0; // NULL Test

	printf("sys: ");
	len_sys = printf("%p", z_p);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%p", z_p);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	void *opt_p = (void *)-0x484468464fa; // Optional Test

	printf("sys: ");
	len_sys = printf("%p", opt_p);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%p", opt_p);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n-----------------------------END_PTR_TEST-----------------------------\n");

	printf("_____________________________START_PERC+SPEC_TEST____________________________\n\n");

	char *norm_per = "%%"; // Positive Test

	printf("sys: ");
	len_sys = printf("%%", norm_per);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%%", norm_per);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *neg_per = "Good"; // One Percent Test

	printf("sys: ");
	len_sys = printf("%", neg_per);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%", neg_per);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *neg_spec = "Bad"; // Wrong Specifier Test

	printf("sys: ");
	len_sys = printf("%w", neg_spec);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%w", neg_spec);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *emp = "Bad"; // No Variable Test

	printf("input: %s\n", emp);
	printf("sys: ");
	len_sys = printf("%d");
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%d");
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);


	printf("\n-----------------------------END_PERC+SPEC_TEST-----------------------------\n");

	printf("_____________________________START_UNSIGNED_TEST____________________________\n\n");

	unsigned int pos_u = 546546554; // Positive Test

	printf("sys: ");
	len_sys = printf("%u", pos_u);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%u", pos_u);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	unsigned int neg_u = -546546554; // Negative Test

	printf("sys: ");
	len_sys = printf("%u", neg_u);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%u", neg_u);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	unsigned int gar_u; // Garbage Test

	printf("sys: ");
	len_sys = printf("%u", gar_u);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%u", gar_u);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n-----------------------------END_UNSIGNED_TEST-----------------------------\n");



	return (0);
}
