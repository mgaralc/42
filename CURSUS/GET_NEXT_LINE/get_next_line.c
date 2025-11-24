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

static int	find_newline(char *stash)
{
	int	i;

	if (!stash)
    return (-1);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (-1);
	return (i + 1);
}

char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	i = find_newline(stash);
	if (i == -1)
	{
		free(stash);
		return (NULL);
	}
	new = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

static char	*safe_join(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	if (!tmp)
	{
		free(stash);
		return (NULL);
	}
	return (tmp);
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    return (NULL);
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		stash = safe_join(stash, buffer);
			if (!stash)
			return (NULL);
	}
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
