/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:27:57 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/28 11:15:37 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	check_elements(t_cub *cub, char *line)
{
	if (cub->elements.no != 1 || cub->elements.we != 1 || cub->elements.so != 1
		|| cub->elements.ea != 1 || cub->elements.c != 1
		|| cub->elements.f != 1)
	{
		if (cub->textures.north_texture)
			mlx_delete_texture(cub->textures.north_texture);
		if (cub->textures.south_texture)
			mlx_delete_texture(cub->textures.south_texture);
		if (cub->textures.west_texture)
			mlx_delete_texture(cub->textures.west_texture);
		if (cub->textures.east_texture)
			mlx_delete_texture(cub->textures.east_texture);
		free(line);
		write(2, "Error!\n", 7);
		exit(1);
	}
}

char	*parse_textures(int fd, char *line, t_cub *cub)
{
	char	**s;

	while (1)
	{
		line = get_next_line(fd);
		if ((!line || ft_strchr(line, '1')) && !ft_strchr(line, ','))
			break ;
		line = remove_newline(line);
		s = ft_split(line, ' ');
		if (!s[0] || (s[0][0] == '\0' && !s[1]))
		{
			free(line);
			double_free(s);
			continue ;
		}
		if (!parse_paths(s, cub) && !parse_colors(line, s, cub))
			free_ressources(cub, line, s, NULL);
		else
		{
			free(line);
			double_free(s);
		}
	}
	check_elements(cub, line);
	return (line);
}
