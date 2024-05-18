#include <criterion/criterion.h>
#include <stdlib.h>
#include "libft.h"

void	identity(void *osef)
{
	(void) osef;
}

Test(lstclear, basics)
{
	int	a = 42;
	t_list	*node_a = ft_lstnew((void *)&a);
	int	b = 0;
	t_list	*node_b = ft_lstnew((void *)&b);
	int	c = -3583;
	t_list	*node_c = ft_lstnew((void *)&c);
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, node_a);
	ft_lstadd_front(&lst, node_b);
	ft_lstadd_front(&lst, node_c);
	ft_lstclear(&lst, identity);

	char	*str1 = strdup("Mammouth ecrase les prix");
	char	*str2 = strdup("Mamie ecrase les prouts");
	char	*str3 = strdup("Que d'humour !");
	t_list	*node_str1 = ft_lstnew((void *)&str1);
	t_list	*node_str2 = ft_lstnew((void *)&str2);
	t_list	*node_str3 = ft_lstnew((void *)&str3);

	ft_lstadd_front(&lst, node_str1);
	ft_lstadd_front(&lst, node_str2);
	ft_lstadd_front(&lst, node_str3);
	ft_lstclear(&lst, free);
}
