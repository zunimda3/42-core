/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 03:36:49 by z                 #+#    #+#             */
/*   Updated: 2026/08/14 10:23:19 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(char c, va_list *ap, int *count)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		conversion_num(c, ap, count);
	else
		conversion_other(c, ap, count);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == '\0')
				break ;
			fmt++;
			conversion(*fmt, &ap, &count);
			fmt++;
		}
		else
			count += write(1, fmt++, 1);
	}
	va_end(ap);
	return (count);
}
