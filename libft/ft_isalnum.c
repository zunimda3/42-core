/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:14:43 by naamir            #+#    #+#             */
/*   Updated: 2026/08/02 17:02:42 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	char	a;
	char	zero;
	char	symbol;

	a = 'a';
	zero = '0';
	symbol = '^';
	printf("a = %d\n", ft_isalnum(a));
	printf("zero = %d\n", ft_isalnum(zero));
	printf("symbol = %d\n", ft_isalnum(symbol));
}
*/
