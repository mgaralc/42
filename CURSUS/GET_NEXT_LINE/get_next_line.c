/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:57:46 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/24 14:27:42 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    char        buffer[BUFFER_SIZE + 1];
    ssize_t     bytes_read;

    bytes_read = 1;
    while (!ft_strchr(stash, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return (NULL);
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
	
	extract_line(stash);

    return (NULL);
}

char *extract_line(char *stash)
{
	int	i;
	char	*linea;

	i = 0;
	if (!stash)
		return (NULL);
	
	while ((stash[i] != '\n') && stash[i])
	{
		i++;
	}
	
	linea = malloc(i * sizeof(char));
	i = 0;

	while (stash[i])
	{
		linea[i] = stash[i];
		i++;
	}
	
	
}
