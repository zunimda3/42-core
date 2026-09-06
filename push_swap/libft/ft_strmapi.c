/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:43:14 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 14:57:59 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// static char	n_tolower(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'A' && c <= 'Z')
// 		return (c + 32);
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

/*
int	main(void)
{
	char	str[] = "NaIm AmIr";
	char	*res;

	res = ft_strmapi(str, n_tolower);
	printf("str: %s, result: %s\n", str, res);
}
*/
