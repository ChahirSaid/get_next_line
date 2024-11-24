#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#else
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# elif BUFFER_SIZE > (INT_MAX - 1)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE (INT_MAX - 1)
# endif
#endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_haschar(char *str, char target);

#endif/*GET_NEXT_LINE_H*/