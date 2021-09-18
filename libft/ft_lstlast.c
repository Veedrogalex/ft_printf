#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*list;

	list = lst;
	while (list && list->next)
		list = list->next;
	return (list);
}
