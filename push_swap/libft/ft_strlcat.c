/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:57:48 by naamir            #+#    #+#             */
/*   Updated: 2026/08/02 17:02:42 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	i;

	lend = 0;
	while (lend < size && dst[lend])
		lend++;
	lens = 0;
	while (src[lens])
		lens++;
	if (lend == size || size == 0)
		return (size + lens);
	i = 0;
	while (i < size - lend - 1 && src[i])
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}

/*
int	main(void)
{
	char	destination[] = "nama saya:";
	char	source[] = "naim";

	printf("before\nsource: %s, destination: %s\n", source, destination);
	printf("return value: %zu\n", ft_strlcat(destination, source, 15));
	printf("updated destination: %s\n", destination);
}
*/
