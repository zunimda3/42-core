/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:40:00 by z                 #+#    #+#             */
/*   Updated: 2026/07/25 18:05:10 by z                ###   ########.fr       */
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

	i = 0;
	j = start;
	if (s[i])
		len_s = strlen(s);
	if (start > len_s)
		len = 0;
	res = malloc((len_s + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (len > 0 && s[i])
	{
		res[i] = s[j];
		j++;
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
