/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:10:55 by gabriel           #+#    #+#             */
/*   Updated: 2026/08/11 16:55:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	i = 0;
	while (i < size + 1)
	{
		if (*str == (char)c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

char	*strjoin_free(char *stash, char *buffer)
{
	char	*new_stash;

	new_stash = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer)
				+ 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strcat(buffer, stash, new_stash);
	free(stash);
	return (new_stash);
}

char	*ft_strcat(char *buffer, char *stash, char *new_stash)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_strlen(stash))
	{
		new_stash[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new_stash[i + j] = buffer[j];
		j++;
	}
	new_stash[i + j] = '\0';
	return (new_stash);
}

size_t	line_size(char *str)
{
	size_t	size;

	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;
	return (size);
}
