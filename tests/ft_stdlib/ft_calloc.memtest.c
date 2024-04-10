/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.memtest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:09:52 by parden            #+#    #+#             */
/*   Updated: 2024/04/10 11:48:16 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include <criterion/criterion.h>
#include <sanitizer/lsan_interface.h>
#include "../../include/ft_stdlib.h"
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
	int *array = ft_calloc(UINT_MAX,sizeof(int));
	cr_expect_null(array);
	cr_expect_eq(errno,ENOMEM);
}

Test(calloc, exact_range, .signal = SIGABRT)
{
	char *s = ft_calloc(10000,sizeof(char));
	char c = s[10000];
	(void) c;
	free(s);
}

Test(calloc, product_overflows)
{
	size_t i = ULONG_MAX/4 + 2;
	int *array = ft_calloc(i,sizeof(int));
	cr_expect_null(array);
	cr_expect_eq(errno,ENOMEM);
}

Test(calloc, no_length, .signal = SIGABRT)
{
	int *array = ft_calloc(0,sizeof(int));
	int i = *array;
	i++;
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

