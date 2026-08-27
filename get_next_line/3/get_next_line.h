/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:37:37 by z                 #+#    #+#             */
/*   Updated: 2026/08/27 19:39:30 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *str, char c);
char	*ft_substr(char *str, size_t len);
char	*ft_strjoin(char *saved, char *chunk);
ssize_t	read_line(char **saved, char *chunk, int fd);
char	*extract_line(char **saved, char *chunk);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
