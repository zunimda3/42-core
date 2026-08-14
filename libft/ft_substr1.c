/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:22:18 by z                 #+#    #+#             */
/*   Updated: 2026/07/25 18:28:31 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s;
	char	*res;

	if (!s)
		return (NULL);
	len_s = strlen(s);
	if (start >= len_s)
		len = 0;
	else if (len > len_s - start)
		len = len_s - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && s[j])
	{
		res[i] = s[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
