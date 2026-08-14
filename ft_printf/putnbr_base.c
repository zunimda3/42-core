/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:01:52 by z                 #+#    #+#             */
/*   Updated: 2026/08/14 10:26:48 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_base(uintptr_t n, char *base, int *count)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (n >= len)
		putnbr_base(n / len, base, count);
	*count += write(1, &base[n % len], 1);
}
