#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *buf;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		buf = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(buf, del);
	}
}
