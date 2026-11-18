#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


char *get_next_line(int fd)
{
    static char *saved;
}