/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:14:50 by schahir           #+#    #+#             */
/*   Updated: 2024/11/26 13:14:55 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * ft_calloc - Allocate and zero-initialize memory
 *
 * @count: Number of elements to allocate
 * @size: Size of each element
 *
 * Returns: Pointer to allocated memory, or NULL on failure
 */
void	*ft_calloc(size_t count, size_t size)
{
	char	*allocated_memory;
	size_t	total_size;
	size_t	i;

	if (size && count > ((size_t)-1) / size)
		return (NULL);
	total_size = count * size;
	allocated_memory = malloc(total_size);
	if (!allocated_memory)
		return (NULL);
	i = 0;
	while (i < total_size)
		allocated_memory[i++] = 0;
	return (allocated_memory);
}

/**
 * ft_strlen - Calculate the length of a string
 *
 * @str: String to calculate the length of
 *
 * Returns: Length of the string
 */
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/**
 * ft_strdup - Duplicate a string
 *
 * @source: String to duplicate
 *
 * Returns: Pointer to a new string containing a duplicate of the source string
 */
static char	*ft_strdup(const char *source)
{
	char	*duplicate;
	int		len;
	int		i;

	if (!source)
		return (NULL);
	len = ft_strlen((char *)source);
	duplicate = ft_calloc(len + 1, sizeof(char));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (source[i])
	{
		duplicate[i] = source[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

/**
 * ft_strjoin - Concatenate two strings
 *
 * @str1: First string
 * @str2: Second string
 *

	* Returns: Pointer to a new string containing
				the concatenation of the two strings
 */
char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	if (!str1)
		str1 = ft_strdup("");
	result = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, sizeof(char));
	if (!result)
	{
		free(str1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str1[i])
		result[j++] = str1[i++];
	i = 0;
	while (str2[i])
		result[j++] = str2[i++];
	result[j] = '\0';
	free(str1);
	return (result);
}

/**
 * ft_haschar - Check if a character exists in a string
 *
 * @str: String to search
 * @target: Character to search for
 *
 * Returns: 1 if the character is found, 0 otherwise
 */
int	ft_haschar(char *str, char target)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == target)
			return (1);
		str++;
	}
	return (0);
}
