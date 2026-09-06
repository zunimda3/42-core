/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:03:19 by naamir            #+#    #+#             */
/*   Updated: 2026/08/02 17:02:42 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	char	a;
	char	b;

	a = 'a';
	b = '1';
	printf("a = %d\n", ft_isdigit(a));
	printf("1 = %d\n", ft_isdigit(b));
}
*/
