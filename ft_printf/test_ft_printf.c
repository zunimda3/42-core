/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:18:22 by z                 #+#    #+#             */
/*   Updated: 2026/08/14 10:22:47 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	str[] = "naim";

	ft_printf("==============\n");
	ft_printf("String\n");
	printf("OG: %s\n", str);
	fflush(stdout);
	ft_printf("FT: %s\n", str);
	ft_printf("==============\n");
	ft_printf("==============\n");
	ft_printf("Integer\n");
	printf("OG: %d %i\n", 10, 10);
	ft_printf("FT: %d %i\n", 10, 10);
	ft_printf("==============\n");
	ft_printf("==============\n");
	ft_printf("Hexadecimal\n");
	printf("OG: %x %X\n", 100000000, 100000000);
	ft_printf("FT: %x %X\n", 100000000, 100000000);
	ft_printf("==============\n");
	ft_printf("==============\n");
	ft_printf("Pointer's address\n");
	printf("OG: %p\n", str);
	ft_printf("FT: %p\n", str);
	ft_printf("==============\n");
	ft_printf("==============\n");
	ft_printf("%% Escape\n");
	printf("OG: %%\n");
	ft_printf("FT: %%\n");
	ft_printf("==============\n");
}
