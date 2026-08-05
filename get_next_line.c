/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 23:38:58 by gabriel           #+#    #+#             */
/*   Updated: 2026/08/05 19:48:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char  *fill_stash(char *fd, char *stash)
{
  char  *buffer;
  unsigned int  bytes_read;
  unsigned int  counter;
  
  while (bytes_read > 0 && strchr(stash, '\n'))
  {
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    counter = 0;
    while (buffer[counter])
    {
      stash[counter] = buffer[counter];
      counter++;
    }
    stash[counter] = '\0'; 
  }
  free(buffer);
  return (stash);
}
char *get_line(char *stash)
{
  unsigned int  counter;
  unsigned int  size;
  char  *line;

  counter = 0;
  size = strlen(stash);
  line = malloc(sizeof(char) * size + 1);
  if (!line)
    return (NULL);
  while (stash[counter] && stash[counter] != '\n')
  {
    line[counter] = stash[counter];
    counter++;
  }
  line[counter] = '\n';
  return (line);
}

char  *process_stash(char *stash)
{
  
}

char	*get_next_line(int fd)
{
	char		*str;
  static char    *stash;
	int			bytes_read;
	int			counter;

  fill_stash(fd, stash);
  get_line(stash);
  stash++;
	return (stash);
}
