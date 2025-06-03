/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:17 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/01 17:49:53 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
		uint32_t color)
{
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
		mlx_put_pixel(image, x, y, color);
}

mlx_texture_t	*choose_texture(t_cub cub, int x)
{
	mlx_texture_t	*texture;

	if (cub.ray[x].wall_side == 'N')
		texture = cub.textures.north_texture;
	if (cub.ray[x].wall_side == 'S')
		texture = cub.textures.south_texture;
	if (cub.ray[x].wall_side == 'W')
		texture = cub.textures.west_texture;
	if (cub.ray[x].wall_side == 'E')
		texture = cub.textures.east_texture;
	return (texture);
}

uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	int		i;
	uint8_t	read;
	uint8_t	green;
	uint8_t	blue;
	uint8_t	alpha;

	i = (y * texture->width + x) * 4;
	read = texture->pixels[i + 0];
	green = texture->pixels[i + 1];
	blue = texture->pixels[i + 2];
	alpha = texture->pixels[i + 3];
	return ((read << 24) | (green << 16) | (blue << 8) | (alpha));
}

int	draw_textured_wall_column(t_cub *cub, int wall_height, int wall_top, int x)
{
	int		y;
	int		tex_x;
	int		tex_y;
	float	wall_pos;
	int		wall_bottom;

	if (cub->ray[x].wall_side == 'N' || cub->ray[x].wall_side == 'S')
		wall_pos = fmod(cub->ray[x].wall_hit_x, TILE);
	else
		wall_pos = fmod(cub->ray[x].wall_hit_y, TILE);
	tex_x = (wall_pos * choose_texture(*cub, x)->width) / TILE;
	y = wall_top;
	wall_bottom = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	if (wall_bottom > WINDOW_HEIGHT)
		wall_bottom = WINDOW_HEIGHT;
	while (y < wall_bottom)
	{
		wall_pos = (float)(y - ((WINDOW_HEIGHT / 2) - (wall_height / 2)));
		tex_y = (int)((wall_pos * choose_texture(*cub, x)->height)
				/ wall_height);
		my_mlx_put_pixel(cub->mlx.img_ptr, x, y,
			get_texture_color(choose_texture(*cub, x), tex_x, tex_y));
		y++;
	}
	return (y);
}

void	draw_3d(t_cub *cub, int x)
{
	int		y;
	float	distance;
	int		wall_top;
	int		wall_height;
	float	fisheye_handled;

	distance = cub->ray[x].distance_to_wall;
	fisheye_handled = distance
		* cos(degree_to_radian(normalize_angle(cub->ray[x].ray_angle
					- cub->ply.ply_angle)));
	distance = fisheye_handled;
	wall_height = (TILE * WINDOW_HEIGHT) / distance;
	wall_top = ((WINDOW_HEIGHT / 2) - (wall_height / 2));
	if (wall_top < 0)
		wall_top = 0;
	y = -1;
	while (++y < wall_top)
		my_mlx_put_pixel(cub->mlx.img_ptr, x, y, cub->textures.ceiling_color);
	y = draw_textured_wall_column(cub, wall_height, wall_top, x) - 1;
	while (++y < WINDOW_HEIGHT)
		my_mlx_put_pixel(cub->mlx.img_ptr, x, y, cub->textures.floor_color);
}
