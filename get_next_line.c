/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 23:38:58 by gabriel           #+#    #+#             */
/*   Updated: 2026/07/27 23:18:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*str;
	int		bytes_read;
  static int i;
  int counter;
	char	buffer[BUFFER_SIZE];

  bytes_read = read(fd, buffer, BUFFER_SIZE);
  printf("%s\n", buffer);
  printf("%c\n\n", buffer[0]);
  str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!str)
    return (NULL);
  counter = 0;
  i = 0;
  //while (buffer[i] != '\n' && buffer[i])
  //{
//
  //}
  str[counter] = '\0';
  printf("%s, vish", str);
	return (str);
}
