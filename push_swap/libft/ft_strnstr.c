/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:17:07 by naamir            #+#    #+#             */
/*   Updated: 2026/08/02 17:02:42 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenl;

	lenl = 0;
	if (*little == '\0')
		return ((char *)(big));
	while (little[lenl])
		lenl++;
	i = 0;
	while (i + lenl <= len && big[i])
	{
		j = 0;
		while ((i + j < len) && big[i + j] == little[j])
		{
			j++;
			if (!little[j])
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*little;
	char	*big;

	little = "naimamir";
	big = "naim";
	printf("result: %s\n", ft_strnstr(big, little, 10));
}
*/
