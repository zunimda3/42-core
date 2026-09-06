/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:28:15 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 15:28:15 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*res;

	if (nmemb != 0 && size > (SIZE_MAX / nmemb))
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
		res[i++] = 0;
	return (res);
}

/*
int	main(void)
{
	int	*res;

	res = ft_calloc(4, sizeof(int));
	if (!res)
		return (1);
	printf("%d %d %d %d\n", res[0], res[1], res[2], res[3]);
	free(res);
	return (0);
}
*/
