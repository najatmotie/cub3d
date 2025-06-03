/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:52:48 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/03 14:31:53 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	dda(t_cub *cub, t_dda dda)
{
	int		i;
	float	x_increment;
	float	y_increment;

	if (!inside_bounds(*cub, dda.end_x / (TILE * MINIMAP), dda.end_y / (TILE
				* MINIMAP)))
		return ;
	dda.distance_x = dda.end_x - dda.start_x;
	dda.distance_y = dda.end_y - dda.start_y;
	if (abs(dda.distance_x) > abs(dda.distance_y))
		dda.pixels_steps = abs(dda.distance_x);
	else
		dda.pixels_steps = abs(dda.distance_y);
	x_increment = dda.distance_x / (float)dda.pixels_steps;
	y_increment = dda.distance_y / (float)dda.pixels_steps;
	i = 0;
	while (i < dda.pixels_steps)
	{
		my_mlx_put_pixel(cub->mlx.img_ptr, round(dda.start_x),
			round(dda.start_y), 0xF5F5F5FF);
		dda.start_x += x_increment;
		dda.start_y += y_increment;
		i++;
	}
}

void	draw_rays(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		cub->dda.start_x = cub->ply.ply_x * TILE * MINIMAP;
		cub->dda.start_y = cub->ply.ply_y * TILE * MINIMAP;
		cub->dda.end_x = cub->ray[i].wall_hit_x * MINIMAP;
		cub->dda.end_y = cub->ray[i].wall_hit_y * MINIMAP;
		dda(cub, cub->dda);
		i++;
	}
}

void	draw_player(t_cub *cub)
{
	int	i;
	int	j;
	int	screen_x;
	int	screen_y;

	j = -4;
	screen_x = cub->ply.ply_x * TILE * MINIMAP;
	screen_y = cub->ply.ply_y * TILE * MINIMAP;
	while (j < 4)
	{
		i = -4;
		while (i < 4)
		{
			if (i * i + j * j <= 4 * 4)
				my_mlx_put_pixel(cub->mlx.img_ptr, screen_x + j, screen_y + i,
					0xF5F5F5FF);
			i++;
		}
		j++;
	}
}

void	draw_tile(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;
	int	screen_y;
	int	screen_x;

	j = 0;
	while (j < TILE * MINIMAP)
	{
		i = 0;
		while (i < TILE * MINIMAP)
		{
			screen_x = x * TILE * MINIMAP + i;
			screen_y = y * TILE * MINIMAP + j;
			my_mlx_put_pixel(cub->mlx.img_ptr, screen_x, screen_y, color);
			i++;
		}
		j++;
	}
}

void	draw_minimap(t_cub *cub)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (y < cub->map.height && y < WINDOW_HEIGHT / (TILE * MINIMAP))
	{
		x = 0;
		while (x < cub->map.width && WINDOW_WIDTH / (TILE * MINIMAP))
		{
			if (cub->map.map[y][x] == '1')
				color = 0xB5B5B5FF;
			else
				color = 0x85A98F00;
			draw_tile(cub, x, y, color);
			x++;
		}
		y++;
	}
	draw_player(cub);
	draw_rays(cub);
}
