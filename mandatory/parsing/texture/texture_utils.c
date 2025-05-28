/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:28:00 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/28 11:10:23 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_ressources(t_cub *cub, char *line, char **s, char **values)
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
	double_free(s);
	double_free(values);
	write(2, "Error!\n", 7);
	exit(1);
}

char	*remove_newline(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(s));
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	free(s);
	str[i] = '\0';
	return (str);
}
