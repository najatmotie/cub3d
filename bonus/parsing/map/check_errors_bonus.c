/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:44 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/02 13:26:02 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	check_empty(int width, char **map)
{
	int	i;
	int	j;

	i = 0;
	if (map[0] == NULL)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (j == width)
			return (1);
		i++;
	}
	return (0);
}

int	check_content_of_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j] != '\0')
		{
			if (cub->map.map[i][j] != '0' && cub->map.map[i][j] != '1'
				&& cub->map.map[i][j] != 'N' && cub->map.map[i][j] != 'S'
				&& cub->map.map[i][j] != 'E' && cub->map.map[i][j] != 'W'
				&& cub->map.map[i][j] != ' ')
				return (1);
			if (check_info_of_player(cub, i, j))
				return (1);
			j++;
		}
		i++;
	}
	if (cub->elements.n == 0 && cub->elements.s == 0 && cub->elements.w == 0
		&& cub->elements.e == 0)
		return (1);
	return (0);
}

bool	is_something_other_occurred(char **map, int i, int j)
{
	if ((map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != 'N'
			&& map[i][j - 1] != 'S' && map[i][j - 1] != 'W' && map[i][j
			- 1] != 'E') || (map[i][j + 1] != '1' && map[i][j + 1] != '0'
			&& map[i][j + 1] != 'N' && map[i][j + 1] != 'S' && map[i][j
			+ 1] != 'W' && map[i][j + 1] != 'E') || (map[i - 1][j] != '1'
			&& map[i - 1][j] != '0' && map[i - 1][j] != 'N' && map[i
			- 1][j] != 'S' && map[i - 1][j] != 'W' && map[i - 1][j] != 'E')
		|| (map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != 'N'
			&& map[i + 1][j] != 'S' && map[i + 1][j] != 'W' && map[i
			+ 1][j] != 'E'))
		return (true);
	return (false);
}

int	check_wall_is_closed(int width, int height, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
					return (1);
				if (is_something_other_occurred(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_errors(t_cub *cub)
{
	if (check_empty(cub->map.width, cub->map.map) || check_content_of_map(cub)
		|| check_wall_is_closed(cub->map.width, cub->map.height, cub->map.map))
	{
		free_textures(cub);
		double_free(cub->map.map);
		write(2, "Error!\n", 7);
		exit(1);
	}
}
