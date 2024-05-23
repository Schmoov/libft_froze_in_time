/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:00:46 by parden            #+#    #+#             */
/*   Updated: 2024/05/23 12:35:40 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*catch_alloc(t_list *lst, void (*del)(void *), void	*maybe_cont)
{
	if (maybe_cont)
		del(maybe_cont);
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	head;
	t_list	*tmp;
	void	*tmp_cont;

	if (!lst)
		return (NULL);
	head.next = NULL;
	tmp = &head;
	while (lst)
	{
		tmp_cont = f(lst->content);
		if (!tmp_cont)
			return (catch_alloc(head.next, del, NULL));
		tmp->next = ft_lstnew(tmp_cont);
		tmp = tmp->next;
		if (!tmp)
			return (catch_alloc(head.next, del, tmp_cont));
		lst = lst->next;
	}
	return (head.next);
}
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	head;
	t_list	*tmp;
	void	*tmp_cont;

	if (!lst)
		return (NULL);
	head.next = NULL;
	tmp = &head;
	while (lst)
	{
		tmp_cont = f(lst->content);
		tmp->next = ft_lstnew(tmp_cont);
		tmp = tmp->next;
		if (!tmp)
		{
			del(tmp_cont);
			ft_lstclear(&head.next, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head.next);
}
*/
/*
static t_list	*malloc_failed(t_list **res, void (*del)(void *), void *todel)
{
	if (todel)
		del(todel);
	ft_lstclear(res, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*tmp_cont;

	res = ft_lstnew(NULL);
	if (!lst || !res)
		return (NULL);
	tmp_cont = f(lst->content);
	if (!tmp_cont)
		return (NULL);
	res->content = tmp_cont;
	tmp = res;
	lst = lst->next;
	while (lst)
	{
		tmp_cont = f(lst->content);
		if (!tmp_cont)
			return (malloc_failed(&res, del, NULL));
		tmp->next = ft_lstnew(tmp_cont);
		tmp = tmp->next;
		if (!tmp)
			return (malloc_failed(&res, del, tmp_cont));
		lst = lst->next;
	}
	return (res);
}
*/
