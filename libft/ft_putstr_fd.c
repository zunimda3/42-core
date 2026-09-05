/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:49:50 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 15:33:03 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, (s++), 1);
}

/*
int	main(void)
{
	char	str[] = "naim amir";

	ft_putstr_fd(str, 1);
}
*/
