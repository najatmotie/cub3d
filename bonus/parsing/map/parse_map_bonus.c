/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:52 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/28 11:18:08 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	handle_first_line(t_cub *cub, char *line, char **map)
{
	int	j;

	j = 0;
	if (line)
	{
		while (line[j] != '\n' && line[j] != '\0')
		{
			map[0][j] = line[j];
			j++;
		}
		if (j < cub->map.width)
		{
			while (j++ < cub->map.width)
				map[0][j] = ' ';
		}
		if (j < cub->map.width)
		{
			while (j < cub->map.width)
			{
				cub->map.map[0][j] = ' ';
				j++;
			}
		}
		map[0][j] = '\0';
	}
}

void	copy_line(t_cub *cub, char *line, int i)
{
	int	j;

	j = 0;
	while (line[j] != '\n' && line[j] != '\0')
	{
		cub->map.map[i][j] = line[j];
		j++;
	}
	if (j < cub->map.width)
	{
		while (j < cub->map.width)
		{
			cub->map.map[i][j] = ' ';
			j++;
		}
	}
	cub->map.map[i][j] = '\0';
}

void	fill_map(t_cub *cub, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (line && ft_strcmp(line, "\n") != 0)
		copy_line(cub, line, i);
	free(line);
	line = NULL;
}

void	parse_map(t_cub *cub, char *line, int fd)
{
	int	i;

	i = 0;
	cub->map.map = malloc((cub->map.height + 1) * sizeof(char *));
	while (i < cub->map.height)
	{
		cub->map.map[i] = malloc(cub->map.width + 1);
		if (line)
		{
			handle_first_line(cub, line, cub->map.map);
			free(line);
			line = NULL;
			i++;
			continue ;
		}
		fill_map(cub, fd, i);
		i++;
	}
	close(fd);
	cub->map.map[i] = NULL;
	check_errors(cub);
}
