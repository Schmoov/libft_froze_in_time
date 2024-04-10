/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:16:12 by parden            #+#    #+#             */
/*   Updated: 2024/04/06 13:15:38 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ret;

	if (ULONG_MAX/elsize < nelem)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ret = (void *)malloc(nelem * elsize);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nelem * elsize);
	return (ret);
}
