/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:15:13 by schahir           #+#    #+#             */
/*   Updated: 2024/11/26 22:14:57 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# else
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  elif BUFFER_SIZE == INT_MAX
#   undef BUFFER_SIZE
#   define BUFFER_SIZE (2147483646)
#  endif
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_haschar(char *str, char target);

#endif /* GET_NEXT_LINE_H */
