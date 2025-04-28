#include "../cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

void	check_args(char *str)
{
	char	*s;

	s = ft_strrchr(str, '.');
	if (s == NULL)
	{
		write(1, "Must Ending With The .ber\n", 26);
		exit(1);
	}
	if (ft_strcmp(s, ".cub") != 0)
	{
		write(1, "Must Ending With The .ber\n", 26);
		exit(1);
	}
}
