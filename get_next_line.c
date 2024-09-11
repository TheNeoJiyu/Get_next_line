/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:55:21 by antolefe          #+#    #+#             */
/*   Updated: 2024/09/11 15:51:11 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*initialize_buff(int fd, char **stash)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || read(fd, buffer, 0) < 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*fill_line_buffer(int fd, char *stash, char *buffer)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			return (stash);
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			return (stash);
	}
	return (stash);
}

char	*set_line(char *line_buffer)
{
	char	*stash;
	size_t	i;

	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	stash = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - (i + 1));
	if (!stash)
		return (NULL);
	if (*stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	line_buffer[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	char		*tmp;

	buffer = initialize_buff(fd, &stash);
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, stash, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	stash = set_line(line);
	tmp = ft_strdup(line);
	free(line);
	return (tmp);
}
