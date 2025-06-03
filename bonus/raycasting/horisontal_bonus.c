/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horisontal_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:32 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/03 14:39:52 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_ray	get_first_tile_ray_h(t_cub *cub, float ray_angle)
{
	t_ray	ray;
	int		value;
	float	opposite;
	float	adjacent;

	ray.wall_hit_x = cub->ply.ply_x * TILE;
	ray.wall_hit_y = cub->ply.ply_y * TILE;
	if (ray_angle >= 0 && ray_angle <= 180)
	{
		value = ray.wall_hit_y / TILE;
		opposite = ray.wall_hit_y - value * TILE;
		ray.wall_hit_y -= opposite;
	}
	else
	{
		value = ray.wall_hit_y / TILE;
		opposite = (value * TILE + TILE) - ray.wall_hit_y;
		ray.wall_hit_y += opposite;
	}
	adjacent = opposite / fabs(tan(degree_to_radian(ray_angle)));
	if (ray_angle >= 90 && ray_angle <= 270)
		ray.wall_hit_x -= adjacent;
	else
		ray.wall_hit_x += adjacent;
	return (ray);
}

t_ray	complete_ray_until_hit_wall_h(t_cub *cub, t_ray ray, float ray_angle)
{
	int		map_x;
	int		map_y;
	float	opposite;
	float	adjacent;

	opposite = TILE;
	adjacent = opposite / fabs(tan(degree_to_radian(ray_angle)));
	while (inside_bounds(*cub, ray.wall_hit_x / TILE, ray.wall_hit_y / TILE))
	{
		map_x = (int)ray.wall_hit_x / TILE;
		map_y = (int)ray.wall_hit_y / TILE;
		if (ray_angle < 180)
			map_y = (int)(ray.wall_hit_y - 1) / TILE;
		if (cub->map.map[map_y][map_x] == '1')
			break ;
		if (ray_angle >= 0 && ray_angle <= 180)
			ray.wall_hit_y -= opposite;
		else
			ray.wall_hit_y += opposite;
		if (ray_angle >= 90 && ray_angle <= 270)
			ray.wall_hit_x -= adjacent;
		else
			ray.wall_hit_x += adjacent;
	}
	return (ray);
}

t_ray	get_horisontal(t_cub *cub, float ray_angle)
{
	t_ray	ray;

	ray = get_first_tile_ray_h(cub, ray_angle);
	ray = complete_ray_until_hit_wall_h(cub, ray, ray_angle);
	ray.distance_to_wall = calculate_distance(cub->ply.ply_x * TILE,
			cub->ply.ply_y * TILE, ray.wall_hit_x, ray.wall_hit_y);
	return (ray);
}
