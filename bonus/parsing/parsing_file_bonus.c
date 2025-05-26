/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:40:00 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/26 13:01:02 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	return (fd);
}

void	parsing_file(t_cub *cub, char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	get_map_size(file, cub);
	fd = open_file(file);
	line = parse_textures(fd, line, cub);
	parse_map(cub, line, fd);
}
