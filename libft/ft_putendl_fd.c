/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:51:49 by naamir            #+#    #+#             */
/*   Updated: 2026/08/08 15:33:23 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, (s++), 1);
	write(fd, "\n", 1);
}

/*
int	main(void)
{
	char	str[] = "naim amir";

	ft_putendl_fd(str, 1);
}
*/
