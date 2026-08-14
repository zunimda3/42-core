/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:02:43 by z                 #+#    #+#             */
/*   Updated: 2026/08/14 10:12:51 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_other(char c, va_list *ap, int *count)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(*ap, char *);
		if (!str)
			*count += write(1, "(null)", 6);
		else
			while (*str)
				*count += write(1, str++, 1);
	}
	else if (c == '%')
		*count += write(1, "%", 1);
	else if (c == 'c')
	{
		c = (char)va_arg(*ap, int);
		*count += write(1, &c, 1);
	}
	else
		*count += write(1, &c, 1);
}
