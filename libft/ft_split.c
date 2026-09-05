/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:19:01 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 15:37:27 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*extract_word(const char *s, char c, size_t *index)
{
	size_t	start;
	size_t	len;
	char	*res;

	while (s[(*index)] && s[(*index)] == c)
		(*index)++;
	start = (*index);
	len = 0;
	while (s[(*index)] && s[(*index)] != c)
	{
		len++;
		(*index)++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, &s[start], len);
	res[len] = '\0';
	return (res);
}

static void	free_tab(char **tab, size_t i)
{
	while (i > 0)
	{
		free(tab[--i]);
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	words;
	char	**res;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	index = 0;
	i = 0;
	while (i < words)
	{
		res[i] = extract_word(s, c, &index);
		if (!res[i])
		{
			free_tab(res, i);
			return (NULL);
		}
		i++;
	}
	res[i] = 0;
	return (res);
}

/*
int	main(void)
{
	char	**res;
	int		i;

	res = ft_split("naim,amir,42kl", ',');
	if (!res)
		return (1);
	i = 0;
	while (res[i])
	{
		printf("result[%d]: %s\n", i, res[i]);
		free(res[i++]);
	}
	free(res);
	return (0);
}
*/
