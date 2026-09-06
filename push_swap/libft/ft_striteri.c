/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:11:16 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 14:59:24 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// void	n_toupper(unsigned int i, char *str)
// {
// 	(void)i;
// 	if (*str >= 'a' && *str <= 'z')
// 		*str = *str - 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
int	main(void)
{
	char	str[] = "NaiM AmiR";

	printf("Before: %s\n", str);
	ft_striteri(str, n_toupper);
	printf("After: %s\n", str);
}
*/
