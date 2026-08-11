/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 23:38:58 by gabriel           #+#    #+#             */
/*   Updated: 2026/08/11 17:08:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*fill_stash(int fd, char *stash, int bytes_read)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = strjoin_free(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}

static char	*get_line(char *stash)
{
	size_t	counter;
	size_t	size;
	char	*line;

	counter = 0;
	size = line_size(stash);
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	while (counter < size)
	{
		line[counter] = stash[counter];
		counter++;
	}
	line[counter] = '\0';
	return (line);
}

static char	*process_stash(char *stash)
{
	size_t	size;
	size_t	stash_size;
	size_t	i;
	size_t	j;
	char	*new_stash;

	size = line_size(stash);
	stash_size = ft_strlen(stash);
	new_stash = malloc(sizeof(char) * ((stash_size - size) + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i = size;
	j = 0;
	while (i < stash_size)
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash, 1);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = get_line(stash);
	stash = process_stash(stash);
	return (line);
}
