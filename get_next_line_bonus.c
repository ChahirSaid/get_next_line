/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:13:57 by schahir           #+#    #+#             */
/*   Updated: 2024/11/26 20:45:24 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_file(int fd, char *buffer)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	temp_buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!temp_buffer)
		return (NULL);
	while (!buffer || !ft_haschar(buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp_buffer), free(buffer), NULL);
		if (bytes_read == 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
		if (!buffer)
			return (free(temp_buffer), NULL);
	}
	free(temp_buffer);
	return (buffer);
}

static char	*ft_extract_line(char *buffer, int *line_len)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, 1);
	else
		line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	*line_len = i;
	return (line);
}

static char	*ft_update_buffer(char *buffer, int start_pos)
{
	char	*new_buffer;
	int		i;
	int		j;

	if (!buffer[start_pos])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer) - start_pos + 1, 1);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = start_pos;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;
	int			line_len;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_line(buffer[fd], &line_len);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_update_buffer(buffer[fd], line_len);
	return (line);
}
