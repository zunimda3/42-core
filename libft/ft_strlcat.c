/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:04:28 by z                 #+#    #+#             */
/*   Updated: 2026/07/21 21:05:03 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dstsize && dst[i])
	{
		i++;
	}
	j = 0;
	while ((i + j) < dstsize && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (i + j);
}
