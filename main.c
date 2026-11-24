#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


    int main(void)
    {
        int fd;
        char *line;
    
        fd = open("test.txt", O_RDONLY);
        int fd1 = open("text1.txt", O_RDONLY | O_CREAT);
        // while ((line = get_next_line(fd)) != NULL)
        // {
        //     printf("%s", line);
        //     free(line);
        // }
        // while ((line = get_next_line(fd1)) != NULL)
        // {
        //     printf("%s", line);
        //     free(line);
        // }

        printf("%s\n",line = get_next_line(fd));
        free(line);
        printf("%s\n",line = get_next_line(fd1));
        free(line);
        close(fd);
        close(fd1);
        return (0);
    }
