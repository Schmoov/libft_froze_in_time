/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:31:27 by parden            #+#    #+#             */
/*   Updated: 2024/05/21 18:14:38 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

static bool	is_in(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	if (set[i])
		return (true);
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	start = 0;
	while (is_in(s1[start], set))
		start++;
	len = ft_strlen(s1);
	while (len && is_in(s1[len - 1], set))
		len--;
	if (len > start)
		len -= start;
	return (ft_substr(s1, start, len));
}
