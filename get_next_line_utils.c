/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:10:55 by gabriel           #+#    #+#             */
/*   Updated: 2026/08/05 18:17:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  strlen(char *str)
{
  size_t  counter;
  
  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}

char	*strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;
	char	*str;

	str = (char *)s;
	size = strlen(str);
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