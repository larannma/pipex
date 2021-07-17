#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (lst == NULL)
		return (0);
	res = ft_lstnew(f(lst->content));
	if (res == NULL)
	{
		ft_lstclear(&res, del);
		return (NULL);
	}
	res->next = ft_lstmap(lst->next, f, del);
	return (res);
}
