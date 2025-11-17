/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:33:15 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/17 15:54:48 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	f_list	*tmp;

	tmp = lst;
	if (!lst || !del)
                return ;

	while(lst)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
