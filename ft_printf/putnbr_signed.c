/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:02:21 by z                 #+#    #+#             */
/*   Updated: 2026/08/14 10:26:31 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_signed(long n, char *base, int *count)
{
	int	len;

	len = ft_strlen(base);
	if (n < 0)
	{
		n *= -1;
		*count += write(1, "-", 1);
	}
	if (n >= len)
		putnbr_signed(n / len, base, count);
	*count += write(1, &base[n % len], 1);
}
