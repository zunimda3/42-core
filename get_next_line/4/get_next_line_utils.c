/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:26:17 by naamir            #+#    #+#             */
/*   Updated: 2026/08/29 14:10:38 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *saved, char c)
{
	size_t	i;

	if (!saved || !*saved)
		return (NULL);
	i = 0;
	while (saved[i])
	{
		if (saved[i] == c)
			return (&saved[i]);
		i++;
	}
	if (saved[i] == c)
		return (&saved[i]);
	return (NULL);
}

char	*ft_substr(char *saved, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(len + 1);
	while (i < len)
	{
		res[i] = saved[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *saved, char *chunk)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!saved || !*saved)
		return (NULL);
	i = 0;
	while (saved && saved[i])
		i++;
	j = 0;
	while (chunk[j])
		j++;
	res = malloc(i + j + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (saved && *saved)
		res[i++] = *saved++;
	while (*chunk)
		res[i++] = *chunk++;
	res[i] = '\0';
	return (res);
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
	size_t	len_line;

	if (!saved || !*saved)
		return (free(chunk), free(saved), saved = NULL, NULL);
	len_line = 0;
	while (*saved[len_line] && *saved[len_line] != '\n')
		len_line++;
	len_line += (*saved[len_line] == '\n');
	line = ft_substr(*saved, len_line);
	if (*saved[len_line])
	{
		leftover = ft_strjoin(NULL, *saved + len_line);
		if (!leftover)
			return (free(line), free(chunk), free(*saved), *saved = NULL, NULL);
	}
	free(*saved);
	*saved = leftover;
	return (line);
}
