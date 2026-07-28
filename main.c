/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:38:00 by gabriel           #+#    #+#             */
/*   Updated: 2026/07/27 23:18:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("sample.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
