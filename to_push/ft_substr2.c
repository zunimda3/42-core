/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 22:00:20 by z                 #+#    #+#             */
/*   Updated: 2026/07/31 22:06:43 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	size_t	i;
	size_t	j;
	char	*res;

	if (!s)
		return (NULL);
	lens = strlen(s);
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
