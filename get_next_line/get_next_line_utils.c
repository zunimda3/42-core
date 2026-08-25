/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:42:38 by z                 #+#    #+#             */
/*   Updated: 2026/08/16 13:35:07 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (0);
}

char	*ft_strjoin(char *saved, char *chunk)
{
	int		total_size;
	char	*res;
	char	*result;
	int		len_saved;
	int		len_chunk;

	len_saved = 0;
	if (saved)
		len_saved = ft_strlen(saved);
	len_chunk = ft_strlen(chunk);
	total_size = len_saved + len_chunk + 1;
	res = malloc(total_size);
	if (!res)
		return (NULL);
	result = res;
	while (saved && *saved)
		*res++ = *saved++;
	while (*chunk)
		*res++ = *chunk++;
	*res = '\0';
	return (result);
}

char	*ft_get_line(char *saved)
{
	int		count;
	char	*res;
	char	*found;
	char	*result;

	if (!saved || !*saved)
		return (NULL);
	found = ft_strchr(saved, '\n');
	if (found)
		count = (int)(found - saved + 1);
	else
		count = ft_strlen(saved);
	res = malloc(count + 1);
	if (!res)
		return (NULL);
	result = res;
	while (count-- > 0)
		*res++ = *saved++;
	*res = '\0';
	return (result);
}

char	*ft_get_leftover(char *saved)
{
	char	*found;
	int		len;
	char	*res;
	char	*result;

	found = ft_strchr(saved, '\n');
	if (found)
	{
		if (*(found + 1))
		{
			found++;
			len = ft_strlen(found);
		}
		else
			return (NULL);
		res = malloc(len + 1);
		if (!res)
			return (NULL);
		result = res;
		while (*found)
			*res++ = *found++;
		*res = '\0';
		return (result);
	}
	else
		return (NULL);
}
