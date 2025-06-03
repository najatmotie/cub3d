/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:27:57 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/02 13:28:01 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	cleanup(char *line, char **s)
{
	free(line);
	double_free(s);
}

void	free_ressources(t_cub *cub, char *line, char **s, char **values)
{
	free(line);
	free_textures(cub);
	double_free(s);
	double_free(values);
	write(2, "Error!\n", 7);
	exit(1);
}

void	check_elements(t_cub *cub, char *line)
{
	if (cub->elements.no != 1 || cub->elements.we != 1 || cub->elements.so != 1
		|| cub->elements.ea != 1 || cub->elements.c != 1
		|| cub->elements.f != 1)
		free_ressources(cub, line, NULL, NULL);
}

char	*remove_newline(t_cub *cub, char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(line));
	if (!str)
		failure_handling(cub, line, -3);
	while (line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	free(line);
	str[i] = '\0';
	return (str);
}

char	*parse_textures(t_cub *cub, char *line, int fd)
{
	char	**s;

	while (1)
	{
		line = get_next_line(fd);
		if ((!line || ft_strchr(line, '1')) && !ft_strchr(line, ','))
			break ;
		if (ft_strchr(line, '\n'))
			line = remove_newline(cub, line);
		s = ft_split(line, ' ');
		if (!s[0] || (s[0][0] == '\0' && !s[1]))
		{
			cleanup(line, s);
			continue ;
		}
		if (!parse_paths(cub, s) && !parse_colors(cub, line, s))
			free_ressources(cub, line, s, NULL);
		else
			cleanup(line, s);
	}
	check_elements(cub, line);
	return (line);
}
