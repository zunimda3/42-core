/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:26:31 by z                 #+#    #+#             */
/*   Updated: 2026/08/25 13:16:31 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *saved, char c)
{
	if (!saved || !*saved)
		return (NULL);
	while (*saved)
	{
		if (*saved == c)
			return (saved);
		saved++;
	}
	if (*saved == c)
		return (saved);
	return (NULL);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	char	*result;
	size_t	i;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *saved, char *chunk)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	while (saved && saved[i])
		i++;
	j = 0;
	while (chunk[j])
		j++;
	result = malloc(i + j + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (saved && *saved)
		result[i++] = *saved++;
	while (*chunk)
		result[i++] = *chunk++;
	result[i] = '\0';
	return (result);
}

ssize_t	read_line(char **saved, char *chunk, int fd)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = read(fd, chunk, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	chunk[bytes_read] = '\0';
	temp = ft_strjoin(*saved, chunk);
	if (!temp)
		return (-1);
	free(*saved);
	*saved = temp;
	return (bytes_read);
}

char	*extract_line(char **saved, char *chunk)
{
	char	*line;
	char	*leftover;
	size_t	line_len;

	if (!*saved || !**saved)
		return (free(chunk), free(*saved), *saved = NULL, NULL);
	line_len = 0;
	while ((*saved)[line_len] && (*saved)[line_len] != '\n')
		line_len++;
	line_len += ((*saved)[line_len] == '\n');
	line = ft_substr(*saved, 0, line_len);
	if (!line)
		return (free(chunk), free(*saved), *saved = NULL, NULL);
	leftover = NULL;
	if ((*saved)[line_len])
		leftover = ft_strjoin(NULL, *saved + line_len);
	if ((*saved)[line_len] && !leftover)
		return (free(line), free(chunk), free(*saved), *saved = NULL, NULL);
	free(chunk);
	free(*saved);
	*saved = leftover;
	return (line);
}
