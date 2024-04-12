/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:40:38 by parden            #+#    #+#             */
/*   Updated: 2024/04/12 11:28:24 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/libft.h"

static size_t	count_char(int n)
{
	size_t	count;

	count = 0;
	if (!n)
		return (0);
	if (n < 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void stack_itoa(int n, char *s)
{
	size_t	len;

	len = count_char(n);
	s[len] = 0;
	if (!n)
		*s = '0';
	if (n < 0)
		*s = '-';
	while (n/10)
	{
		res[len - 1] = n % 10;
		len--;
		n /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char s[12];

	stack_itoa(n, s);
	ft_putstr_fd(s, fd);
}
