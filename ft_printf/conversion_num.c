/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:05:51 by z                 #+#    #+#             */
/*   Updated: 2026/08/14 11:43:23 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_num(char c, va_list *ap, int *count)
{
	char	*ptr;

	if (c == 'd' || c == 'i')
		putnbr_signed((long)va_arg(*ap, int), "0123456789", count);
	else if (c == 'u')
		putnbr_base(va_arg(*ap, unsigned int), "0123456789", count);
	else if (c == 'x')
		putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef", count);
	else if (c == 'X')
		putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF", count);
	else if (c == 'p')
	{
		ptr = va_arg(*ap, void *);
		if (!ptr)
			*count += write(1, "(nil)", 5);
		else
		{
			*count += write(1, "0x", 2);
			putnbr_base((uintptr_t)ptr, "0123456789abcdef", count);
		}
	}
}
