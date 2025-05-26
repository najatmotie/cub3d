/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:36 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/26 13:00:29 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

bool	check_wall(t_cub cub, int x, int y, float ray_angle)
{
	if (cub.map.map[y][x] == '1' || (cub.map.map[y][x] == '0' && cub.map.map[y
			- 1][x] == '1' && cub.map.map[y][x - 1] == '1'
			&& (int)ray_angle == 315) || (cub.map.map[y][x] == '0'
			&& cub.map.map[y - 1][x] == '1' && cub.map.map[y][x + 1] == '1'
			&& (int)ray_angle == 225) || (cub.map.map[y][x] == '0'
			&& cub.map.map[y + 1][x] == '1' && cub.map.map[y][x + 1] == '1'
			&& (int)ray_angle == 135) || (cub.map.map[y][x] == '0'
			&& cub.map.map[y + 1][x] == '1' && cub.map.map[y][x - 1] == '1'
			&& (int)ray_angle == 45))
		return (true);
	return (false);
}

t_ray	shortest_distance(t_ray horisontal, t_ray vertical, float ray_angle)
{
	if (horisontal.distance_to_wall <= vertical.distance_to_wall)
	{
		if (sin(degree_to_radian(normalize_angle(ray_angle))) > 0)
			horisontal.wall_side = 'N';
		else
			horisontal.wall_side = 'S';
		return (horisontal);
	}
	if (cos(degree_to_radian(normalize_angle(ray_angle))) > 0)
		vertical.wall_side = 'E';
	else
		vertical.wall_side = 'W';
	return (vertical);
}

t_ray	cast_ray(t_cub *cub, float ray_angle)
{
	t_ray	ray;
	t_ray	shortest;
	t_ray	vertical;
	t_ray	horisontal;

	vertical = get_vertical(cub, ray_angle);
	horisontal = get_horisontal(cub, ray_angle);
	shortest = shortest_distance(horisontal, vertical, ray_angle);
	ray.ray_angle = ray_angle;
	ray.wall_hit_x = shortest.wall_hit_x;
	ray.wall_hit_y = shortest.wall_hit_y;
	ray.wall_side = shortest.wall_side;
	ray.distance_to_wall = shortest.distance_to_wall;
	return (ray);
}

void	cast_rays(t_cub *cub)
{
	int		x;
	float	fov;
	int		num_rays;
	float	ray_angle;
	float	ray_angle_increment;

	x = 0;
	fov = FOV;
	num_rays = SCREEN_WIDTH;
	ray_angle_increment = fov / num_rays;
	while (x < num_rays)
	{
		ray_angle = normalize_angle((cub->ply.ply_angle + (fov / 2)) - (x
					* ray_angle_increment));
		cub->ray[x] = cast_ray(cub, ray_angle);
		draw_3d(cub, x);
		x++;
	}
}
