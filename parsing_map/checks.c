#include "../cub3d.h"

int	check_empty(int width, char **map)
{
	int i = 0;
	int j = 0;

	while (map[i])
	{
		j = 0;
		if(map[i][j] == '\n' && map[i][j + 1] == '\n')
			return (1);
		while (map[i][j] == ' ')
			j++;
		if(j == width)
			return (1);
		i++;
	}
	return (0);
}

int	check_content_of_map(char **map)
{
	int	i;
	int	j;
        
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' 
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' 
				&& map[i][j] != ' ')
				return (1);
			if(map[i][j] == '0' && map[i][j + 1] == ' ')
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_wall(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
				return (1);
		i++;
	}
	i = 0;
	while(map[i])
	{
		j = width - 1;
		while(map[i][j] == ' ')
			j--;
		if(map[i][j] != '1')
			return (1);
		i++;
	}
	i = 0;
	while(i < width)
	{
		if((map[height - 1][i] != '1' && map[height - 1][i] != ' ') 
		|| (map[0][i] != '1' && map[0][i] != ' '))
			return (1);
		i++;
	}
	return (0);
}

void	check_errors(t_cub cub, int width, int height)
{
	if (check_content_of_map(cub.map.map) || check_wall(cub.map.map, width, height) || check_empty(width, cub.map.map))
	{
		ft_free(cub.map.map);
		write(2, "Error!\n", 7);
		exit(1);
	}
}
