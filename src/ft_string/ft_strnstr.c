/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:18:12 by parden            #+#    #+#             */
/*   Updated: 2024/03/23 13:27:39 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((i < len) && big[i])
	{
		j = 0;
		while (big[i + j] && little[j] && (i + j < len)
			&& (big[i] == little[j]))
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
