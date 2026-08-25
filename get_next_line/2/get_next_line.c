/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:07:16 by z                 #+#    #+#             */
/*   Updated: 2026/08/25 14:38:17 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*chunk;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(saved, '\n') && bytes_read > 0)
	{
		bytes_read = read_line(&saved, chunk, fd);
		if (bytes_read < 0)
		{
			free(chunk);
			free(saved);
			saved = NULL;
			return (NULL);
		}
	}
	return (extract_line(&saved, chunk));
}
