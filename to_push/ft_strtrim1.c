/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 23:51:46 by z                 #+#    #+#             */
/*   Updated: 2026/08/01 02:54:58 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*res;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = start + strlen(s1);
	if (end != start)
		end--;
	while (*start && isset(*start, set))
		start++;
	while (end > start && isset(*end, set))
		end--;
	if (start > end)
		len = 0;
	else
		len = end - start + 1;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	strlcpy(res, start, len + 1);
	return (res);
}

int	main(void)
{
	char	set[] = "ab";
	char	str[] = "aba_hello_world_aba";

	printf("set:%s, str:%s\n", set, str);
	printf("result:%s\n", ft_strtrim(str, set));
}
