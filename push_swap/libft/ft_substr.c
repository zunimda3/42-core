/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:29:01 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 15:29:01 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	size_t	i;
	size_t	j;
	char	*res;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
		len = 0;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i])
	{
		res[j++] = s[i++];
	}
	res[j] = 0;
	return (res);
}

/*
int	main(void)
{
	char	*res;
	char	str[] = "naim amir";

	res = ft_substr(str, 5, 4);
	if (!res)
		return (1);
	printf("str: %s, result: %s\n", str, res);
	free(res);
	return (0);
}
*/
