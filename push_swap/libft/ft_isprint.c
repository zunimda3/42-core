/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:33:52 by naamir            #+#    #+#             */
/*   Updated: 2026/08/02 17:02:42 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	char	a;
	char	symbol;
	char	notprintable;

	a = 'a';
	symbol = '^';
	notprintable = '\t';
	printf("a = %d\n", ft_isprint(a));
	printf("symbol = %d\n", ft_isprint(symbol));
	printf("notprintable = %d\n", ft_isprint(notprintable));
}
*/
