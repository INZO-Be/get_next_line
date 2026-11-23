#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

// while ((line = get_next_line(fd)) != NULL)
// {
//     printf("%s", line);
//     free(line);
// }
line = get_next_line(fd);
printf("%s", line);
line = get_next_line(fd);
printf("%s", line);
line = get_next_line(fd);
printf("%s", line);
line = get_next_line(fd);
printf("%s", line);
line = get_next_line(fd);
printf("%s", line);
line = get_next_line(fd);
printf("%s", line);
close(fd);
}