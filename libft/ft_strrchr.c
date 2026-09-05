/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:44:54 by naamir            #+#    #+#             */
/*   Updated: 2026/08/02 17:02:42 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			res = (char *)&s[i];
		}
		i++;
	}
	if ((char)c == 0)
		return ((char *)&s[i]);
	return (res);
}

/*
int	main(void)
{
	char	str[] = "nama saya naim";

	printf("str: %s\nresult: %s\n", str, ft_strrchr(str, (int) ' '));
}
*/
