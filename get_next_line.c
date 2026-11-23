#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *ft_strchar(char *s, char c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    if (*s == c)
        return (s);
    return 0;
}
static int ft_strlen(char *s)
{
    int i;
    i = 0;
    while (s[i])
        i++;
    return i;
}

static char *ft_strjoin(char *s1, char *s2)
{
    char *jme3;
    int i;
    int l;
    i = 0;
    l = 0;
    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    jme3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!jme3)
        return (NULL);
    while (s1[i])
    {
        jme3[i] = s1[i];
        i++;
    }
    while (s2[l])
    {
        jme3[i++] = s2[l++];
    }
    jme3[i] = '\0';
    return (jme3);
}
static char *read_toshtash(char *stash, int fd)
{
    char *buffer;
    char *joined;
    int byte_read;
    
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (!ft_strchar(stash, '\n'))
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read < 0)
        return (free(buffer), free(stash), stash = NULL, NULL);
    if (byte_read == 0)
        break;
    buffer[byte_read] = '\0';
    joined = ft_strjoin(stash, buffer);
    if (!joined)
        return (free(buffer), free(stash), NULL);
    free(stash);
    stash = joined;
    }
    free(buffer);
    return (stash);
}
char *ft_strlcopy(char *dst, char *src, int len)
{
    int i;
    i = 0;
    if (!dst || !src)
        return NULL;
    while (i < len)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}
char *ft_strdup(char *stash)
{
    char *rest;
    int i;

    i = 0;
    rest = malloc(ft_strlen(stash) + 1);
    if (!rest)
        return NULL;
    while (stash[i])
    {
        rest[i] = stash[i];
        i++;
    }
    rest[i] = '\0';
    return rest;
}
void line_plus(char **stash, int i)
{
    char *tmp;
    tmp = 0;
    if ((*stash)[i])
    {
        tmp = ft_strdup(&(*stash)[i]);
        if (!tmp)
        {
            free(*stash);
            *stash = NULL;
            return;
        }
        free(*stash);
        *stash = tmp;
    }else {
        free(*stash);
        *stash = NULL;
    }
}
char *line(char **stash)
{
    char *line;
    int i;
    i = 0;
    if (!*stash)
        return (NULL);
    while ((*stash)[i] && (*stash)[i] != '\n')
        i++;
    if ((*stash)[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
    {
        free(*stash);
        stash = NULL;
        return (NULL);
    }
    ft_strlcopy(line, *stash, i);
    line_plus(stash, i);
    return line;
}

char *get_next_line(int fd)
{
    static char *stash;
    stash = read_toshtash(stash, fd);
    if (!stash)
        return (NULL);
    return (line(&stash));
}
int main()
{
    int fd = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    close(fd);
}