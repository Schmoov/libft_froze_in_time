#include "libft.h"
#include <stdio.h>

int main ()
{
	int a = 3;
	int b = 4;
	t_list	*na=ft_lstnew((void *)&a);
	t_list	*nb=ft_lstnew((void *)&b);
	na->next = nb;
	printf("%d\n",*(int *)(ft_lstlast(na)->content));
}
