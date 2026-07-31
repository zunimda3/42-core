/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:07:31 by z                 #+#    #+#             */
/*   Updated: 2026/07/25 20:07:31 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	res = malloc((strlen(s1) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (set[i])
	{
		j = 0;
		while (s1[j])
		{
			if (s1[j] != set[i])
				res[k] = s1[j];
			j++;
			k++;
		}
		i++;
	}
	if (!res)
		res[0] = '\0';
	res[k] = '\0';
	return (res);
}
