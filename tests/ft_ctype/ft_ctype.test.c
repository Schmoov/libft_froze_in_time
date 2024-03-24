#include <ctype.h>
#include <limits.h>
#include <criterion/criterion.h>
#include "../../include/ft_ctype.h"

Test(ctype, isalnum)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isalnum(i) == !!isalnum(i));
}

Test(ctype, isalpha)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isalpha(i) == !!isalpha(i));
}

Test(ctype, isascii)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isascii(i) == !!isascii(i));
}

Test(ctype, isdigit)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isdigit(i) == !!isdigit(i));
}

Test(ctype, isprint)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isprint(i) == !!isprint(i));
}

Test(ctype, tolower)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(ft_tolower(i) == tolower(i));
}

Test(ctype, toupper)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(ft_toupper(i) == toupper(i));
}
