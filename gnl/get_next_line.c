#include "../cub3d.h"

char	*before_line(char *str)
{
	int		i;
	char	*before;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	else if (str[i] == '\0')
		return (ft_strdup(str));
	before = malloc(i + 1);
	if (before == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		before[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		before[i] = '\n';
	i++;
	before[i] = '\0';
	return (before);
}

char	*after_line(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	j = ft_strlen(str) - i;
	if (j == 0)
	{
		free(str);
		return (NULL);
	}
	rest = malloc(j + 1);
	if (rest == NULL)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		rest[j++] = str[i++];
	free(str);
	rest[j] = '\0';
	return (rest);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*fd_read(int fd, char *line)
{
	ssize_t	n;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	n = 0;
	while (n >= 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == 0)
			break ;
		if (n < 0)
		{
			free(buff);
			free(line);
			return (NULL);
		}
		buff[n] = '\0';
		line = ft_strjoin(line, buff);
		if (check_line(line) == 1)
			break ;
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*read_line;
	static char	*full_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = fd_read(fd, full_line);
	if (!full_line)
		return (NULL);
	read_line = before_line(full_line);
	full_line = after_line(full_line);
	return (read_line);
}
