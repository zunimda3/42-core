/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:24:08 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 14:48:25 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i++] = 0;
	}
}

/*
int	main(void)
{
	char	string[] = "naim";

	ft_bzero((string + 2), 2);
	printf("Input: naim (-2), Exp. Output: na, Result: %s\n", string);
	return (0);
}
*/
