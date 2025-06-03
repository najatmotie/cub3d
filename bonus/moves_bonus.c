/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:04 by nmotie-           #+#    #+#             */
/*   Updated: 2025/06/02 13:33:09 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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

void	forward_move(t_cub *cub)
{
	float	new_x;
	float	new_y;

	new_x = (cub->ply.ply_x + cos(degree_to_radian(cub->ply.ply_angle))
			* MOVE_SPEED);
	new_y = (cub->ply.ply_y - sin(degree_to_radian(cub->ply.ply_angle))
			* MOVE_SPEED);
	if (inside_bounds(*cub, new_x, new_y) && can_move(*cub, new_x, new_y))
	{
		cub->ply.ply_x = new_x;
		cub->ply.ply_y = new_y;
	}
}

void	backward_move(t_cub *cub)
{
	float	new_x;
	float	new_y;

	new_x = (cub->ply.ply_x - cos(degree_to_radian(cub->ply.ply_angle))
			* MOVE_SPEED);
	new_y = (cub->ply.ply_y + sin(degree_to_radian(cub->ply.ply_angle))
			* MOVE_SPEED);
	if (inside_bounds(*cub, new_x, new_y) && can_move(*cub, new_x, new_y))
	{
		cub->ply.ply_x = new_x;
		cub->ply.ply_y = new_y;
	}
}

void	right_move(t_cub *cub)
{
	float	new_x;
	float	new_y;

	new_x = (cub->ply.ply_x - cos(degree_to_radian(cub->ply.ply_angle) + M_PI
				/ 2) * MOVE_SPEED);
	new_y = (cub->ply.ply_y + sin(degree_to_radian(cub->ply.ply_angle) + M_PI
				/ 2) * MOVE_SPEED);
	if (inside_bounds(*cub, new_x, new_y) && can_move(*cub, new_x, new_y))
	{
		cub->ply.ply_x = new_x;
		cub->ply.ply_y = new_y;
	}
}

void	left_move(t_cub *cub)
{
	float	new_x;
	float	new_y;

	new_x = (cub->ply.ply_x + cos(degree_to_radian(cub->ply.ply_angle) + M_PI
				/ 2) * MOVE_SPEED);
	new_y = (cub->ply.ply_y - sin(degree_to_radian(cub->ply.ply_angle) + M_PI
				/ 2) * MOVE_SPEED);
	if (inside_bounds(*cub, new_x, new_y) && can_move(*cub, new_x, new_y))
	{
		cub->ply.ply_x = new_x;
		cub->ply.ply_y = new_y;
	}
}
