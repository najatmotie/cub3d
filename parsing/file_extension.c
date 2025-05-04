#include "../cub3d.h"

void	check_file(char *file)
{
	char	*s;

	s = ft_strrchr(file, '.');
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
