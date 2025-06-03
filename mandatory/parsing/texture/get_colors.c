/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:27:51 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/29 18:36:13 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool	floor_color(t_cub *cub, char *line, char **s)
{
	int		r;
	int		g;
	int		b;
	char	**values;

	if (s[0] && s[1] && ft_strcmp(s[0], "F") == 0 && !s[2])
	{
		values = ft_split(s[1], ',');
		if (values[0] && values[1] && values[2] && !values[3])
		{
			r = ft_atoi(values[0]);
			g = ft_atoi(values[1]);
			b = ft_atoi(values[2]);
			if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
				free_ressources(cub, line, s, values);
			double_free(values);
			cub->elements.f++;
			cub->textures.floor_color = (r << 24) | (g << 16) | (b << 8) | 255;
			return (true);
		}
		else
			free_ressources(cub, line, s, values);
	}
	return (false);
}

bool	ceiling_color(t_cub *cub, char *line, char **s)
{
	int		r;
	int		g;
	int		b;
	char	**values;

	if (s[0] && s[1] && ft_strcmp(s[0], "C") == 0 && !s[2])
	{
		values = ft_split(s[1], ',');
		if (values[0] && values[1] && values[2] && !values[3])
		{
			r = ft_atoi(values[0]);
			g = ft_atoi(values[1]);
			b = ft_atoi(values[2]);
			if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
				free_ressources(cub, line, s, values);
			double_free(values);
			cub->elements.c++;
			cub->textures.ceiling_color = 
				(r << 24) | (g << 16) | (b << 8) | 255;
			return (true);
		}
		else
			free_ressources(cub, line, s, values);
	}
	return (false);
}

bool	parse_colors(t_cub *cub, char *line, char **s)
{
	if (!floor_color(cub, line, s) && !ceiling_color(cub, line, s))
		return (false);
	return (true);
}
