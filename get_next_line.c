/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:15:14 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/30 21:09:37 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static	char	*buffer[MAX_FD][BUFFER_SIZE];

// 	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 )
// 		return (NULL);
	
// }

// static char *BUFFER[][]

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && size > 0 && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*extract_line(char *buffer)
{
	size_t	len;
	char	*line;

	if (!buffer[0])
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		line = ft_substr(buffer, 0, len + 1);
	else
		line = ft_substr(buffer, 0, len);
	return (line);
}

void	shift_buffer(char *buffer)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		buffer[0] = '\0';
		return ;
	}
	len++;
	i = 0;
	while (buffer[len])
		buffer[i++] = buffer[len++];
	buffer[i] = '\0';
}

char	*read_and_store(int fd, char *buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*new_buffer;

	new_buffer = ft_strdup(buffer);
	while (!ft_strchr(new_buffer, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		tmp[bytes_read] = '\0';
		new_buffer = ft_strjoin(new_buffer, tmp);
		if (!new_buffer)
			return (NULL);
	}
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	char		*full_content;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	full_content = read_and_store(fd, buffer[fd]);
	if (!full_content)
		return (NULL);
	line = extract_line(full_content);
	free(full_content);
	shift_buffer(buffer[fd]);
	return (line);
}
