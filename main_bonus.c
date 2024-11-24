#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int main(int ac, char **av)
{
    int fd, fd1, fd2;

    // Ensure the program is given at least 3 arguments
    if (ac < 4) {
        printf("Usage: %s <file1> <file2> <file3>\n", av[0]);
        return 1;
    }

    // Open the files and check for errors
    fd = open(av[1], O_RDONLY);
    fd1 = open(av[2], O_RDONLY);
    fd2 = open(av[3], O_RDONLY);

    if (fd == -1 || fd1 == -1 || fd2 == -1) {
        perror("Error opening files");
        return 1;
    }

    // Read and print lines from each file descriptor
    printf("File 1:\n");
    while (1) {
        char *line = get_next_line(fd);
        if (!line) break;
        printf("%s", line);
        free(line);
    }

    printf("\nFile 2:\n");
    while (1) {
        char *line = get_next_line(fd1);
        if (!line) break;
        printf("%s", line);
        free(line);
    }

    printf("\nFile 3:\n");
    while (1) {
        char *line = get_next_line(fd2);
        if (!line) break;
        printf("%s", line);
        free(line);
    }

    close(fd);
    close(fd1);
    close(fd2);

    return 0;
}
