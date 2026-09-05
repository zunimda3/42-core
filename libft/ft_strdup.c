/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:28:28 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 15:28:28 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = 0;
	while (s[len])
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

/*
int	main(void)
{
	char	*res;
	char	str[] = "naim amir";

	res = ft_strdup(str);
	if (!res)
		return (1);
	printf("str: %s, result: %s\n", str, res);
	free(res);
	return (0);
}
*/
