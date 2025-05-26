/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:27:57 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/26 13:03:38 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	check_elements(t_cub *cub)
{
	if (cub->elements.no != 1 || cub->elements.we != 1 || cub->elements.so != 1
		|| cub->elements.ea != 1 || cub->elements.c != 1
		|| cub->elements.f != 1)
	{
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
			free_ressources(line, s, NULL);
		else
		{
			free(line);
			double_free(s);
		}
	}
	check_elements(cub);
	return (line);
}
