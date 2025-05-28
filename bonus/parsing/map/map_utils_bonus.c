/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:48 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/28 11:27:33 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	skip_identifiers(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if ((!line || ft_strchr(line, '0') || ft_strchr(line, '1'))
			&& !ft_strchr(line, ','))
			break ;
		free(line);
	}
	free(line);
}

void	get_map_size(char *file, t_cub *cub)
{
	int		fd;
	char	*line;
	int		fix_width;

	fix_width = 0;
	cub->map.width = 0;
	cub->map.height = 0;
	fd = open_file(file);
	skip_identifiers(fd);
	while (1)
	{
		cub->map.height++;
		line = get_next_line(fd);
		if (!line || ft_strcmp(line, "\n") == 0)
			break ;
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
