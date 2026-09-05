/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:20:42 by naamir            #+#    #+#             */
/*   Updated: 2026/08/29 13:58:09 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *saved, char c);
char	*ft_substr(char *saved, size_t len);
char	*ft_strjoin(char *saved, char *chunk);
ssize_t	read_line(char **saved, char *chunk, int fd);
char	*extract_line(char **saved, char *chunk);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
