#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char	*ft_strchar(char *s, char c)
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
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*jme3;
	int		i;
	int		l;

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

static char	*read_toshtash(char *stash, int fd)
{
	char	*buffer;
	char	*joined;
	int		byte_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	while (!ft_strchar(stash, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buffer), free(stash), NULL);
		if (byte_read == 0)
			break ;
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

char	*get_next_line_bonus(int fd)
{
	static char	*stash[1024];

	if (fd < 0 || fd > 1024|| BUFFER_SIZE <= 0)
		return (free(stash[fd]), NULL);
	stash[fd] = read_toshtash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	return (line(&stash[fd]));
}
