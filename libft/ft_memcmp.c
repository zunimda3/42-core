/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:40:45 by naamir            #+#    #+#             */
/*   Updated: 2026/08/02 17:02:42 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*src1;
	unsigned const char	*src2;
	size_t				i;

	i = 0;
	src1 = s1;
	src2 = s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && src1[i] == src2[i])
		i++;
	return ((int)src1[i] - src2[i]);
}

/*
int	main(void)
{
	char	s1[] = "nai";
	char	s2[] = "naima";

	printf("result: %d\n", ft_memcmp(s1, s2, 5));
}
*/
