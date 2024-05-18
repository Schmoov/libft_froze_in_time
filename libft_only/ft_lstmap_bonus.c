/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:00:46 by parden            #+#    #+#             */
/*   Updated: 2024/05/18 16:40:01 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	res = ft_lstnew(f(lst->content));
	if (!res)
	{
		del(res->content);
		free(res);
		return (NULL);
	}
	tmp = res;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		tmp = tmp->next;
		if (!tmp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (res);
}
