#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (c == *s)
			return ((char *)s);
		s++;
	}
	if (c == *s)
		return ((char *)s);
	return (NULL);
}