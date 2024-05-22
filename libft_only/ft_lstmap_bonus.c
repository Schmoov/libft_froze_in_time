/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:00:46 by parden            #+#    #+#             */
/*   Updated: 2024/05/22 18:28:16 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*malloc_failed(t_list **res, void (*del)(void *))
{
	ft_lstclear(res, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*tmp_cont;

	tmp_cont = f(lst->content);
	if (!tmp_cont)
		return (NULL);
	res = ft_lstnew(tmp_cont);
	if (!res)
		return (NULL);
	tmp = res;
	lst = lst->next;
	while (lst)
	{
		tmp_cont = f(lst->content);
		if (!tmp_cont)
			return (malloc_failed(&res, del));
		tmp->next = ft_lstnew(tmp_cont);
		tmp = tmp->next;
		if (!tmp)
			return (malloc_failed(&res, del));
		lst = lst->next;
	}
	return (res);
}
