/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:40:53 by z                 #+#    #+#             */
/*   Updated: 2026/08/27 19:51:19 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
{
	if (!str || !*str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_substr(char *str, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
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
	char	*leftover;
	char	*line;
	size_t	i;

	if (!*saved || !**saved)
		return (free(chunk), free(*saved), *saved = NULL, NULL);
	i = 0;
	while ((*saved)[i] && (*saved)[i] != '\n')
		i++;
	i += (((*saved)[i]) == '\n');
	line = ft_substr(*saved, i);
	if (!line)
		return (free(chunk), free(*saved), *saved = NULL, NULL);
	leftover = NULL;
	if ((*saved)[i])
	{
		leftover = ft_strjoin(NULL, *saved + i);
		if (!leftover)
			return (free(chunk), free(*saved), *saved = NULL, NULL);
	}
	return (free(chunk), free(*saved), *saved = leftover, line);
}
