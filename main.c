#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main (int ac, char **av)
{
    char *line;
    int fd;
    int i;

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        line = get_next_line(fd);
        printf("%s", line);
        while (line)
        {
            line = get_next_line(fd);
            printf("%s", line);
        }
        free(line);
    }
    else if (ac == 3)
    {
        fd = open(av[1], O_RDONLY);
        i = atoi(av[2]);
        while (i)
        {
            line = get_next_line(fd);
            printf("%s", line);
            i--;
        }
        free(line);
    }
    else
        return (1);
    return (0);
}