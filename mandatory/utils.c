/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:08 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/26 16:14:25 by nmotie-          ###   ########.fr       */
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
}

bool	can_move(t_cub cub, int x, int y)
{
	int	px;
	int	py;

	px = (int)cub.ply.ply_x;
	py = (int)cub.ply.ply_y;
	if (cub.map.map[y][x] == '1')
		return (false);
	if (x != px && y != py)
	{
		if (cub.map.map[py][x] == '1' || cub.map.map[y][px] == '1')
			return (false);
	}
	return (true);
}

void	my_mlx_put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
		uint32_t color)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		mlx_put_pixel(image, x, y, color);
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

void	cleanup_ressources(t_cub *cub)
{
	free(cub->ray);
	double_free(cub->map.map);
	if (cub->textures.north_texture)
		mlx_delete_texture(cub->textures.north_texture);
	if (cub->textures.south_texture)
		mlx_delete_texture(cub->textures.south_texture);
	if (cub->textures.west_texture)
		mlx_delete_texture(cub->textures.west_texture);
	if (cub->textures.east_texture)
		mlx_delete_texture(cub->textures.east_texture);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
	mlx_close_window(cub->mlx.mlx_ptr);
}
