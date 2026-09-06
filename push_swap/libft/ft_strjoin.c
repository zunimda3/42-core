/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:28:37 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 15:28:37 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	size;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	size = lens1 + lens2 + 1;
	res = malloc(size * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, lens1);
	ft_memcpy(res + lens1, s2, lens2);
	res[lens1 + lens2] = 0;
	return (res);
}

/*
int	main(void)
{
	char	s1[] = "naim ";
	char	s2[] = "amir";

	printf("s1: %s, s2: %s\n", s1, s2);
	printf("result: %s\n", ft_strjoin(s1, s2));
}
*/
