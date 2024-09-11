/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:56:18 by antolefe          #+#    #+#             */
/*   Updated: 2024/09/11 15:24:24 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*set_line(char *line_buffer);
char	*fill_line_buffer(int fd, char *buffer, char *stash);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*initialize_buff(int fd, char **stash);

#endif
