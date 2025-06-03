/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:08 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/02 13:31:16 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_cub *cub)
{
	cub->elements.n = 0;
	cub->elements.w = 0;
	cub->elements.s = 0;
	cub->elements.e = 0;
	cub->elements.no = 0;
	cub->elements.we = 0;
	cub->elements.so = 0;
	cub->elements.ea = 0;
	cub->elements.c = 0;
	cub->elements.f = 0;
	cub->textures.north_texture = NULL;
	cub->textures.south_texture = NULL;
	cub->textures.west_texture = NULL;
	cub->textures.east_texture = NULL;
}

void	double_free(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_textures(t_cub *cub)
{
	if (cub->textures.north_texture)
		mlx_delete_texture(cub->textures.north_texture);
	if (cub->textures.south_texture)
		mlx_delete_texture(cub->textures.south_texture);
	if (cub->textures.west_texture)
		mlx_delete_texture(cub->textures.west_texture);
	if (cub->textures.east_texture)
		mlx_delete_texture(cub->textures.east_texture);
}

void	failure_handling(t_cub *cub, char *line, int i)
{
	if (i >= 0)
	{
		while (i >= 0)
		{
			free(cub->map.map[i]);
			i--;
		}
		free(cub->map.map);
	}
	if (i == -1)
		double_free(cub->map.map);
	if (i == -2)
		free(cub->map.map);
	free(line);
	free_textures(cub);
	perror("malloc");
	exit(1);
}

void	cleanup_ressources(t_cub *cub)
{
	free(cub->ray);
	double_free(cub->map.map);
	free_textures(cub);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
	mlx_close_window(cub->mlx.mlx_ptr);
}
