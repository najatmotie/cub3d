/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:40:00 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/01 18:58:03 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	check_extension(char *file)
{
	char	*s;

	s = ft_strrchr(file, '.');
	if (!s || ft_strcmp(s, ".cub") != 0)
	{
		write(1, "Must Ending With The .cub\n", 26);
		exit(1);
	}
}

int	skip_identifiers(int fd, int *width)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			return (0);
		}
		if ((ft_strchr(line, '0') || ft_strchr(line, '1')) && !ft_strchr(line,
				','))
		{
			*width = ft_strlen(line) - 1;
			free(line);
			break ;
		}
		free(line);
	}
	return (1);
}

void	get_map_size(t_cub *cub, char *file)
{
	int		fd;
	char	*line;
	int		fix_width;

	fix_width = 0;
	cub->map.width = 0;
	fd = open_file(file);
	cub->map.height = skip_identifiers(fd, &fix_width);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || only_spaces(line))
			break ;
		cub->map.height++;
		cub->map.width = ft_strlen(line) - 1;
		if (fix_width < cub->map.width)
			fix_width = cub->map.width;
		cub->map.width = 0;
		free(line);
	}
	free(line);
	close(fd);
	cub->map.width = fix_width;
}

void	parsing_file(t_cub *cub, char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	get_map_size(cub, file);
	fd = open_file(file);
	line = parse_textures(cub, line, fd);
	parse_map(cub, line, fd);
}
