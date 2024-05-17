/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:09:52 by parden            #+#    #+#             */
/*   Updated: 2024/03/30 12:29:23 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <criterion/criterion.h>
#include "../../include/ft_stdlib.h"

Test(atoi, basic)
{
	cr_assert_eq(atoi("0"), ft_atoi("0"));
	cr_assert_eq(atoi("1"), ft_atoi("1"));
	cr_assert_eq(atoi("-1"), ft_atoi("-1"));
	cr_assert_eq(atoi("2147483647"), ft_atoi("2147483647"));
	cr_assert_eq(atoi("-2147483648"), ft_atoi("-2147483648"));
	cr_assert_eq(atoi("     /t /f/f/n   /n +158385aa57"), ft_atoi("     /t /f/f/n   /n +158385aa56aa57"));
	cr_assert_eq(atoi("--1"), ft_atoi("--1"));
	cr_assert_eq(atoi(""), ft_atoi(""));
	cr_assert_eq(atoi("12 34"), ft_atoi("12 34"));
	cr_assert_eq(atoi("-000154"), ft_atoi("-000154"));
	cr_assert_eq(atoi(" "), ft_atoi(" "));
	cr_assert_eq(atoi(" - "), ft_atoi(" - "));
	cr_assert_eq(atoi(" +"), ft_atoi(" +"));
	cr_assert_eq(atoi(" + 1"), ft_atoi(" + 1"));
	cr_assert_eq(atoi("0000000000000000000000000"), ft_atoi("0000000000000000000000000"));
}

Test(atoi, edge)
{
	cr_assert_eq(0, ft_atoi("2147483648"));
	cr_assert_eq(0, ft_atoi("-2147483649"));
	cr_assert_eq(0, ft_atoi("999999999999999999999999999999999"));
}
