#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*list;

	i = 0;
	list = lst;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
