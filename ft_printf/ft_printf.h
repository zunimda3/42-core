/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:06:51 by z                 #+#    #+#             */
/*   Updated: 2026/08/14 10:28:20 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int				ft_printf(const char *fmt, ...);
void			putnbr_base(uintptr_t n, char *base, int *count);
void			putnbr_signed(long n, char *base, int *count);
void			conversion_num(char c, va_list *ap, int *count);
void			conversion_other(char c, va_list *ap, int *count);
unsigned int	ft_strlen(char *base);

#endif
