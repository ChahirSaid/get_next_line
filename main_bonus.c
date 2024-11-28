#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	read_and_print_lines(int fd)
{
    char *line;
    if ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
}

int	main(int ac, char **av)
{
	int fd, fd1, fd2;
	(void)ac;

	fd = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	fd2 = open(av[3], O_RDONLY);

	read_and_print_lines(fd);
	read_and_print_lines(fd1);
	read_and_print_lines(fd2);


	close(fd);
	close(fd1);
	close(fd2);

	return (0);
}
