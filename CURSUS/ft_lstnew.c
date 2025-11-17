/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:10:14 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/17 11:44:43 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

#include <stdio.h>

int	main(void)
{
	char	hola[] = "Almacename";
	t_list *nodo;

	nodo = ft_lstnew(hola);

	printf("Contenido del nodo: %s\n", (char *)nodo->content);
	free(nodo);

}
