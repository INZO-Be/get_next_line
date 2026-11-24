#include "get_next_line.h"

static char	*ft_strlcopy(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strdup(char *stash)
{
	char	*rest;
	int		i;

	i = 0;
	rest = malloc(ft_strlen(stash) + 1);
	if (!rest)
		return (NULL);
	while (stash[i])
	{
		rest[i] = stash[i];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}

static int	line_plus(char **stash, int i)
{
	char	*tmp;

	tmp = NULL;
	if ((*stash)[i])
	{
		tmp = ft_strdup(&(*stash)[i]);
		if (!tmp)
		{
			free(*stash);
			*stash = NULL;
			return (0);
		}
		free(*stash);
		*stash = tmp;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
	return (1);
}

char	*line(char **stash)
{
	char	*line;
	int		i;

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
		*stash = NULL;
		return (NULL);
	}
	ft_strlcopy(line, *stash, i);
	if (!line_plus(stash, i))
		return (free(line), NULL);
	return (line);
}
