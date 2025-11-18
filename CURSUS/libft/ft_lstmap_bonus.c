/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:10:01 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/18 18:01:57 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
static void	del(void *ptr)
{
	free(ptr);
}

int	main(void)
{
	t_list	*lst;
	t_list	*mapped;
	t_list	*cur;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(strdup("uno")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("dos")));
	mapped = ft_lstmap(lst, map_f, del);
	cur = mapped;
	while (cur)
	{
		printf("%s\n", (char *)cur->content);
		cur = cur->next;
	}
	ft_lstclear(&lst, del);
	ft_lstclear(&mapped, del);
	return (0);
}
*/