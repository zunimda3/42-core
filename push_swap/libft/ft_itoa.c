/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:19:29 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 15:31:36 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_len(int n)
{
	long	number;
	size_t	len;

	number = n;
	len = 0;
	if (number == 0)
		return (1);
	if (number <= 0)
	{
		number *= -1;
		len++;
	}
	while (number >= 1)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static char	*convert_to_str(char *s, int n, size_t len)
{
	long	number;

	number = n;
	if (number == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (number <= 0)
	{
		s[0] = '-';
		number *= -1;
	}
	while (number)
	{
		s[--len] = number % 10 + '0';
		number /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;

	len = find_len(n);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	convert_to_str(res, n, len);
	res[len] = 0;
	return (res);
}

/*
int	main(void)
{
	char	*res;

	res = ft_itoa(-2147483648);
	if (!res)
		return (1);
	printf("result: %s\n", res);
	free(res);
	return (0);
}
*/
