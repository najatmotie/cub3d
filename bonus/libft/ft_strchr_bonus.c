#include "../cub3d_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if(!s)
		return(0);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}