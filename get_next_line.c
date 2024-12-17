/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:15:03 by schahir           #+#    #+#             */
/*   Updated: 2024/11/28 16:53:57 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * ft_read_file - Read from a file descriptor into a buffer
 *
 * @fd: File descriptor to read from
 * @buffer: Existing buffer to append read content
 *
 * Returns: Updated buffer containing read content, or NULL on error
 */
static char	*ft_read_file(int fd, char *buffer)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	temp_buffer = ft_calloc((unsigned long long)BUFFER_SIZE + 1, 1);
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

/**
 * ft_extract_line - Extract a single line from the buffer
 *
 * @buffer: Buffer containing file content
 * @line_len: Pointer to store the length of extracted line
 *
 * Returns: Dynamically allocated string with the extracted line,
	or NULL on error
 */
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

/**
 * ft_update_buffer - Update the buffer with remaining content
 *
 * @buffer: Buffer to update
 * @start_pos: Position to start updating from
 *
 * Returns: Updated buffer with remaining content, or NULL if no content remains
 */
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

/**
 * get_next_line - Read a line from a file descriptor
 *
 * @fd: File descriptor to read from
 *
 * Returns: Dynamically allocated string containing the line read,
	or NULL on error or EOF
 */
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			line_len;

	buffer = ft_read_file(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_extract_line(buffer, &line_len);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_update_buffer(buffer, line_len);
	return (line);
}
