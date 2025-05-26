/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:27:54 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/26 13:02:26 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	north_image(t_cub *cub, char *path)
{
	cub->elements.no++;
	cub->textures.north_texture = mlx_load_png(path);
	if (!cub->textures.north_texture)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
}

void	south_image(t_cub *cub, char *path)
{
	cub->elements.so++;
	cub->textures.south_texture = mlx_load_png(path);
	if (!cub->textures.south_texture)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
}

void	west_image(t_cub *cub, char *path)
{
	cub->elements.we++;
	cub->textures.west_texture = mlx_load_png(path);
	if (!cub->textures.west_texture)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
}

void	east_image(t_cub *cub, char *path)
{
	cub->elements.ea++;
	cub->textures.east_texture = mlx_load_png(path);
	if (!cub->textures.east_texture)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		exit(1);
	}
}

bool	parse_paths(char **s, t_cub *cub)
{
	if (s[2] != NULL)
		return (false);
	if (s[0] && s[1] && ft_strcmp(s[0], "NO") == 0)
	{
		north_image(cub, s[1]);
		return (true);
	}
	else if (s[0] && s[1] && ft_strcmp(s[0], "SO") == 0)
	{
		south_image(cub, s[1]);
		return (true);
	}
	else if (s[0] && s[1] && ft_strcmp(s[0], "WE") == 0)
	{
		west_image(cub, s[1]);
		return (true);
	}
	else if (s[0] && s[1] && ft_strcmp(s[0], "EA") == 0)
	{
		east_image(cub, s[1]);
		return (true);
	}
	return (false);
}
