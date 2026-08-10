/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:10:55 by gabriel           #+#    #+#             */
/*   Updated: 2026/08/10 20:45:23 by gabriel          ###   ########.fr       */
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
	size_t	stash_len;
	size_t	i;
	size_t	j;

	stash_len = ft_strlen(stash);
	new_stash = malloc(sizeof(char) * (stash_len + ft_strlen(buffer) + 1));
	if (!new_stash)
		return (free(stash), NULL);
	i = 0;
	while (i < stash_len)
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
	free(stash);
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
