/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:27:54 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/28 11:26:56 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	north_image(t_cub *cub, char *path)
{
	if (cub->elements.no != 0)
		return (false);
	cub->elements.no++;
	cub->textures.north_texture = mlx_load_png(path);
	if (!cub->textures.north_texture)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (false);
	}
	return (true);
}

bool	south_image(t_cub *cub, char *path)
{
	if (cub->elements.so != 0)
		return (false);
	cub->elements.so++;
	cub->textures.south_texture = mlx_load_png(path);
	if (!cub->textures.south_texture)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (false);
	}
	return (true);
}

bool	west_image(t_cub *cub, char *path)
{
	if (cub->elements.we != 0)
		return (false);
	cub->elements.we++;
	cub->textures.west_texture = mlx_load_png(path);
	if (!cub->textures.west_texture)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (false);
	}
	return (true);
}

bool	east_image(t_cub *cub, char *path)
{
	if (cub->elements.ea != 0)
		return (false);
	cub->elements.ea++;
	cub->textures.east_texture = mlx_load_png(path);
	if (!cub->textures.east_texture)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (false);
	}
	return (true);
}

bool	parse_paths(char **s, t_cub *cub)
{
	if (s[0] && s[1] && !s[2] && ft_strcmp(s[0], "NO") == 0)
	{
		if (!north_image(cub, s[1]))
			return (false);
		return (true);
	}
	else if (s[0] && s[1] && !s[2] && ft_strcmp(s[0], "SO") == 0)
	{
		if (!south_image(cub, s[1]))
			return (false);
		return (true);
	}
	else if (s[0] && s[1] && !s[2] && ft_strcmp(s[0], "WE") == 0)
	{
		if (!west_image(cub, s[1]))
			return (false);
		return (true);
	}
	else if (s[0] && s[1] && !s[2] && ft_strcmp(s[0], "EA") == 0)
	{
		if (!east_image(cub, s[1]))
			return (false);
		return (true);
	}
	return (false);
}
