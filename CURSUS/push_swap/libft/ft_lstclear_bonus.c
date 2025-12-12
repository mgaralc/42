/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:22:20 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/18 17:21:11 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	del(void *ptr)
{
	free(ptr);
}

int	main(void)
{
	t_list	*lst = NULL;
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (1);
	node->content = malloc(5);
	if (!node->content)
	{
		free(node);
		return (1);
	}
	strcpy(node->content, "hola");
	node->next = NULL;
	lst = node;
	ft_lstclear(&lst, del);
	if (lst == NULL)
		printf("lista vaciada\n");
	return (0);
}*/