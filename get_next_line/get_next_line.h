/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 13:14:56 by z                 #+#    #+#             */
/*   Updated: 2026/08/16 13:34:20 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *saved, char *chunk);
char	*ft_get_line(char *saved);
char	*ft_get_leftover(char *saved);
char	*get_next_line(int fd);

#endif
