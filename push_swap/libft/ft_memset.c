/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:09:43 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 14:49:21 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i++] = c;
	}
	return (str);
}

/*
int	main(void)
{
	char	string[] = "naim";

	printf("Input: naim, Exp. Output: 00im, Result: %s\n",
		(char *)ft_memset(string, 48, 2));
	return (0);
}
*/
