/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.memtest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:09:52 by parden            #+#    #+#             */
/*   Updated: 2024/05/18 13:29:14 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include <criterion/criterion.h>
#include <sanitizer/lsan_interface.h>
#include "libft.h"
#include <errno.h>
#include <signal.h>

Test(calloc, basic)
{
	int *array = ft_calloc(10000,sizeof(int));
	for (int i = 0; i < 10000;i++)
		cr_expect_eq(array[i],0);	
	free(array);
	char *s = ft_calloc(1,sizeof(char));
	cr_expect_str_eq(s,"");	
	free(s);
}

Test(calloc, too_big)
{
	int *array = ft_calloc(ULONG_MAX/100 ,sizeof(int));
	cr_expect_null(array);
	cr_expect_eq(errno,ENOMEM);
}

Test(calloc, exact_range, .signal = SIGABRT)
{
	char *s = calloc(10000,sizeof(char));
	s[10001]='X';
	free(s);
}

Test(calloc, product_overflows)
{
	size_t i = ULONG_MAX/4 + 2;
	int *array = ft_calloc(i,sizeof(int));
	cr_expect_null(array);
	cr_expect_eq(errno,ENOMEM);
}
/*
Test(calloc, no_length, .signal = SIGABRT)
{
	int *array = calloc(1,sizeof(int));
	printf("\n\n->%p\n\n", (void *)array);
	free(array);
	//int i = *array;
	//i++;
}

Test(calloc, no_size, .signal = SIGABRT)
{
	int *array = ft_calloc(42,0);
	int i = *array;
	i++;
}

Test(calloc, no_no, .signal = SIGABRT)
{
	int *array = ft_calloc(0, 0);
	int i = *array;
	i++;
}

Test(calloc, leaky, .signal = SIGABRT)
{
    ((char *)ft_calloc(1,1))[0]=0;
    cr_expect(__lsan_do_recoverable_leak_check());
    __lsan_do_leak_check();
}
*/
