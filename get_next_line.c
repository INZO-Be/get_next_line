#include "get_next_line.h"
#include <fcntl.h>



char *get_next_line(int fd)
{

}
int main()
{
    int fd = open("test.txt", O_RDONLY);
    get_next_line(fd);
    get_next_line(fd);

}