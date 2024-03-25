/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:55:11 by parden            #+#    #+#             */
/*   Updated: 2024/03/25 17:39:16 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../include/ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dst;
	size_t	i_src;

	if (!dstsize)
		return (ft_strlen(src));
	i_dst = ft_strlen(dst);
	i_src = 0;
	while (src[i_src] && (i_dst + 1 < dstsize))
	{
		dst[i_dst] = src[i_src];
		i_src++;
		i_dst++;
	}
	dst[i_dst] = 0;
	while (src[i_src])
	{
		i_src++;
		i_dst++;
	}
	return (i_dst);
}
