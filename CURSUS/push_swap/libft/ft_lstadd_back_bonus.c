/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:17:32 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/18 17:21:06 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!alst || !new)
		return ;
	last = ft_lstlast(*alst);
	if (!last)
	{
		*alst = new;
		return ;
	}
	last->next = new;
}
/*
#include <stdio.h>

int main(void)
{
	t_list	a;
	t_list	b;
	t_list	*lst = NULL;

	a.content = "primero";
	a.next = NULL;
	b.content = "segundo";
	b.next = NULL;
	ft_lstadd_back(&lst, &a);
	ft_lstadd_back(&lst, &b);
	printf("%s\n", (char *)lst->content);
	if (lst->next)
		printf("%s\n", (char *)lst->next->content);
	return (0);
}*/