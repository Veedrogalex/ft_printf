#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*newel;

	if (!lst || !f)
		return (NULL);
	list = NULL;
	while (lst)
	{
		if (!(newel = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, newel);
		lst = lst->next;
	}
	return (list);
}
