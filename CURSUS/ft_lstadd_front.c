/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:45:18 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/17 12:57:53 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include "libft.h"
#include <stdio.h>

int main(void)
{
    t_list *lista = NULL;

    t_list *nodo1 = ft_lstnew("B");
    t_list *nodo2 = ft_lstnew("A");

    ft_lstadd_front(&lista, nodo1);
    ft_lstadd_front(&lista, nodo2);

    printf("%s\n", (char *)lista->content);
    printf("%s\n", (char *)lista->next->content);

    return 0;
}
*/
