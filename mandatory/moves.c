/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:50:04 by nmotie-           #+#    #+#             */
/*   Updated: 2025/05/25 20:32:29 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_key(t_cub *cub)
{
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
	mlx_close_window(cub->mlx.mlx_ptr);
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
