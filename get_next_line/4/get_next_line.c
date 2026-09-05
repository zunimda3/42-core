/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:19:25 by naamir            #+#    #+#             */
/*   Updated: 2026/08/29 13:56:38 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*chunk;
	char static	*saved;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	chunk[BUFFER_SIZE] = '\0';
	bytes_read = 1;
	while (!ft_strchr(saved, '\n') && bytes_read > 0)
	{
		bytes_read = read_line(&saved, chunk, fd);
		if (bytes_read < 0)
			return (free(saved), free(chunk), saved = NULL, NULL);
	}
	return (extract_line());
}
