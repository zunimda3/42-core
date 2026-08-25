/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:26:12 by z                 #+#    #+#             */
/*   Updated: 2026/08/25 14:32:09 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strchr(char *saved, char c);
char	*ft_substr(char *str, size_t start, size_t len);
char	*ft_strjoin(char *saved, char *chunk);
ssize_t	read_line(char **saved, char *chunk, int fd);
char	*extract_line(char **saved, char *chunk);
char	*get_next_line(int fd);

#endif
